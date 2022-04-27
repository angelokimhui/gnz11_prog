#!/usr/bin/python
# Basic Calltime Calculator by GNz11(angelolim) - Python Version
# April 27, 2022
import os

#definition of 'calculation' function
def calculation():
    if destination_code == 1:
        if (time_code == 'A' or time_code == 'a'):
            if(day_code == 'X' or time_code == 'x'):
                total_sec = (float(cust_creds/50)*180)
            elif(day_code == 'Y' or day_code == 'y'):
                total_sec = (float(cust_creds/40)*180)
        elif (time_code == 'B' or time_code =='b'):
            if(day_code == 'X' or time_code == 'x'):
                total_sec = (float(cust_creds/45)*180)
            elif(day_code == 'Y' or day_code == 'y'):
                total_sec = (float(cust_creds/38)*180)
    elif destination_code == 2:
        if (time_code == 'A' or time_code == 'a'):
            if(day_code == 'X' or time_code == 'x'):
                total_sec = (float(cust_creds/30)*120)
            elif(day_code == 'Y' or day_code == 'y'):
                total_sec = (float(cust_creds/25)*120)
        elif (time_code == 'B' or time_code =='b'):
            if(day_code == 'X' or time_code == 'x'):
                total_sec = (float(cust_creds/27)*120)
            elif(day_code == 'Y' or day_code == 'y'):
                total_sec = (float(cust_creds/15)*120)
    elif destination_code == 3:
        if (time_code == 'A' or time_code == 'a'):
            if(day_code == 'X' or time_code == 'x'):
                total_sec = (float(cust_creds/40)*180)
            elif(day_code == 'Y' or day_code == 'y'):
                total_sec = (float(cust_creds/35)*180)
        elif (time_code == 'B' or time_code =='b'):
            if(day_code == 'X' or time_code == 'x'):
                total_sec = (float(cust_creds/35)*180)
            elif(day_code == 'Y' or day_code == 'y'):
                total_sec = (float(cust_creds/22)*180)
    elif destination_code == 4:
        if (time_code == 'A' or time_code == 'a'):
            if(day_code == 'X' or time_code == 'x'):
                total_sec = (float(cust_creds/35)*120)
            elif(day_code == 'Y' or day_code == 'y'):
                total_sec = (float(cust_creds/20)*120)
        elif (time_code == 'B' or time_code =='b'):
            if(day_code == 'X' or time_code == 'x'):
                total_sec = (float(cust_creds/30)*120)
            elif(day_code == 'Y' or day_code == 'y'):
                total_sec = (float(cust_creds/19)*120)
    min = (int(total_sec/60))
    seconds = (int(total_sec%60))
    return min,seconds

# Main Function
print("Telephone System")
cust_name = input ("Enter your name : ")
cust_num = input("Enter your number : ")
if len(cust_num)>11:
    print ("You entered beyond the character limit, please try again.")
    exit()
print("\nDestination of your call")
print("       1. American Region")
print("       2. Asia Region")
print("       3. Africa Region")
print("       4. Europe Region")
destination_code = (int(input("\nEnter your choice : ")))
print("\nTime Code : ")
print("       A. Daytime")
print("       B. Nighttime")
time_code = input("\nEnter your choice : ")
print("\nDay Code : ")
print("    X. Weekdays")
print("    Y. Weekends")
day_code = input("\nEnter your choice : ")
cust_creds = float(input("\nEnter your available load/credits : "))

#Start ECHO
os.system('clear')
print("\n Telephone System")
print("==================\n")
print("Customer Name : "+cust_name)
print("Customer Number : "+cust_num)
min, seconds = calculation()
if seconds == 0:
    print("You have "+str(min)+" mins of calltime")
else:
    print("You have "+str(min)+" mins and "+str(seconds)+" of calltime")
print("\nTotal Charges : "+str(cust_creds))
print("==================")
print("\n")
exit()
