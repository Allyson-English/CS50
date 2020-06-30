import cs50
from sys import argv, exit
import csv


def main():

    # Check if correct number of command line arguments have been read in
    if len(argv) != 2:
        print("Usage Error: two command line arguments (.py .csv) required")
        exit(1)

    # Call existing database
    db = cs50.SQL("sqlite:///students.db")
    # db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEST, house TEXT, birth NUMERIC)")

    # Open .CSV file containing names, birthdates and house assignments for each character
    with open(argv[1], "r") as student_data:
        reader = csv.reader(student_data)

        # Pull student names from each column and append as individual lists to master list of student names to be added to SQL database
        # Pull house name and birth year for each student from file and add to student data in SQL database
        for colnams in reader:
            temp_lst = (colnams[0].split(" "))
            if temp_lst[0] == "name":
                continue
            elif len(temp_lst) == 2:
                temp_lst.insert(1, None)
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                temp_lst[0], temp_lst[1], temp_lst[2], colnams[1], colnams[2])


main()
