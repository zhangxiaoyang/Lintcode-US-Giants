#!/usr/bin/env python

import re
import os
import xmltodict
import traceback
from xml.sax.saxutils import unescape

def safe(s):
    return s.strip().replace(' ', '-')

def mkdirp(path):
    try:
        os.makedirs(path)
    except:
        pass

def writeContent(path, content):
    with open(path, 'w') as f:
        f.write(content.encode('utf-8', 'ignore'))

def workflowy2repo(raw, outputDir):
    for group in xmltodict.parse(raw)['opml']['body']['outline']['outline']:
        groupName = safe(unescape(group['@text']))
        for item in group['outline']:
            itemName = safe(unescape(item['@text']))
            path = '/'.join([outputDir, groupName])
            mkdirp(path)
            itemContentList = []
            try:
                for i in item['outline']:
                    itemContentList.append(unescape(i['@text']).strip())
                    if '@_note' in i:
                        itemContentList.append(unescape(i['@_note']).strip())
                    itemContentList.append('\n')
                writeContent('/'.join([path, itemName + '.cpp']), '\n'.join(itemContentList))
            except:
                print traceback.print_exc()

def clean(raw):
    return re.sub(r'(?<=text=")- ', '', raw)

if __name__ == '__main__':
    inputFile = 'workflowy.opml'
    outputDir = 'code'

    print 'Removing old code ...'
    os.system('rm -rf %s/*' % outputDir)

    print 'Generating code ...'
    with open(inputFile, 'r') as f:
        raw = f.read()
        workflowy2repo(clean(raw), outputDir)

    print 'Done!'
