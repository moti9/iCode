enter_time_str = "2016-01-01 15:45:56"
leave_time_str = "2016-01-01 15:46:56"


enter_date, enter_time = enter_time_str.split(' ')
leave_date, leave_time = leave_time_str.split(' ')


enter_year, enter_month, enter_day = map(int, enter_date.split('-'))
leave_year, leave_month, leave_day = map(int, leave_date.split('-'))


enter_hour, enter_minute, enter_second = map(int, enter_time.split(':'))
leave_hour, leave_minute, leave_second = map(int, leave_time.split(':'))


enter_timestamp = enter_second + enter_minute * 60 + enter_hour * 3600
leave_timestamp = leave_second + leave_minute * 60 + leave_hour * 3600

time_spent = (leave_timestamp - enter_timestamp) * 2

print(time_spent)






# from datetime import datetime

# enter_time_str = "2016-01-01 15:45:56"
# leave_time_str = "2016-01-01 15:46:56"

# enter_time = datetime.strptime(enter_time_str, '%Y-%m-%d %H:%M:%S')
# leave_time = datetime.strptime(leave_time_str, '%Y-%m-%d %H:%M:%S')

# time_spent = (leave_time - enter_time).total_seconds() * 2

# print(time_spent)






# import time

# enter_time_str = "2016-01-01 15:45:56"
# leave_time_str = "2016-01-01 15:46:56"

# # Split date and time
# enter_date, enter_time = enter_time_str.split(' ')
# leave_date, leave_time = leave_time_str.split(' ')

# # Split date components
# enter_year, enter_month, enter_day = map(int, enter_date.split('-'))
# leave_year, leave_month, leave_day = map(int, leave_date.split('-'))

# # Split time components
# enter_hour, enter_minute, enter_second = map(int, enter_time.split(':'))
# leave_hour, leave_minute, leave_second = map(int, leave_time.split(':'))

# # Calculate the time spent in seconds
# enter_timestamp = (enter_year, enter_month, enter_day, enter_hour, enter_minute, enter_second, 0, 0, 0)
# leave_timestamp = (leave_year, leave_month, leave_day, leave_hour, leave_minute, leave_second, 0, 0, 0)

# # Calculate the time spent in seconds
# time_spent = (time.mktime(leave_timestamp) - time.mktime(enter_timestamp)) * 2

# print(time_spent)
