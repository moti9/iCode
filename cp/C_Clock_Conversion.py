# from datetime import datetime

tt = int(input())

for _ in range(tt):
    tm = input()
    # dt = datetime.strptime(tm, "%H:%M")
    # ndt = dt.strftime("%I:%M %p")
    # print(ndt)
    hours, minutes = map(int, tm.split(":"))
    meridian = "AM"
    if hours > 12:
        hours -= 12
        meridian = "PM"
    elif hours == 12:
        meridian = "PM"
    elif hours == 0:
        hours = 12
    print(f"{hours:02}:{minutes:02} {meridian}")
