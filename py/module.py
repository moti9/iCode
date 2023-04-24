import calendar
import sys
location = sys.path
# print(location)
for x in location:
    print(x)


leapyr = calendar.leapdays(2000, 2096)
print(leapyr)


sys.path.insert(1, r'C:\mkprg\py\workplace')

import testFile



print(testFile.info)
