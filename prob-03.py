print("Enter number of subject")
sub = int(input())
total = 0
for i in range(sub):
    print("Enter number obtained in subjects:", (i+1))
    total = total + int(input())

avg = total/sub
if (avg >= 80 and avg <= 100):
    print("Final grade: A+")
elif (avg >= 75 and avg <= 79):
    print("Final grade: A")
elif (avg >= 70 and avg <= 74):
    print("Final grade: A-")
elif (avg >= 65 and avg <= 69):
    print("Final grade: B+")
elif (avg >= 60 and avg <= 64):
    print("Final grade: B+")
elif (avg >= 55 and avg <= 59):
    print("Final grade: B+")
elif (avg >= 50 and avg <= 54):
    print("Final grade: C+")
elif (avg >= 45 and avg <= 49):
    print("Final grade: C+")
elif (avg > 40 and avg <= 44):
    print("Final grade: D")
elif (avg <= 39):
    print("Final grade: F")
else:
    print("Invalid Input")
