''''
motik@motiky:/mnt/083760C05DEB8AE8/mkprg/py/HackQuest$ exiftool "Stream Enigma.pdf"
ExifTool Version Number         : 12.65
File Name                       : Stream Enigma.pdf
Directory                       : .
File Size                       : 238 kB
File Modification Date/Time     : 2023:11:29 15:25:00+05:30
File Access Date/Time           : 2024:01:27 10:51:01+05:30
File Inode Change Date/Time     : 2024:01:27 10:51:01+05:30
File Permissions                : -rwxrwxrwx
File Type                       : PDF
File Type Extension             : pdf
MIME Type                       : application/pdf
PDF Version                     : 1.6
Linearized                      : No
Page Count                      : 1
Page Mode                       : UseOutlines
Language                        : en-US
XMP Toolkit                     : Image::ExifTool 12.65
Artist                          : Presenting you the wonderful artist: Mc-18th-Obj
Creator                         : Writer
Producer                        : LibreOffice 7.5
Create Date                     : 2023:11:02 13:25:44+05:30
'''

'''
motik@motiky:/mnt/083760C05DEB8AE8/mkprg/py/HackQuest$ file "Stream Enigma.pdf"
Stream Enigma.pdf: PDF document, version 1.6, 1 pages

'''

'''
Creator:         Writer
Producer:        LibreOffice 7.5
CreationDate:    Thu Nov  2 13:25:44 2023 IST
Custom Metadata: no
Metadata Stream: yes
Tagged:          no
UserProperties:  no
Suspects:        no
Form:            none
Syntax Warning: Bad launch-type link action
JavaScript:      no
Pages:           1
Encrypted:       no
Page size:       595.304 x 841.89 pts (A4)
Page rot:        0
File size:       237717 bytes
Optimized:       no
PDF version:     1.6
'''

'''
xxd "Stream Enigma.pdf" | less

very large info
'''

'''
strings "Stream Enigma.pdf"

very large info
'''

'''
pdf-parser "Stream Enigma.pdf"

No command found
'''