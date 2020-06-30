import cs50
from sys import argv, exit
import csv


def main():

    # Check if correct number of command line arguments have been read in
    if len(argv) != 2:
        print("Usage Error: two command line arguments (.py .csv) required")
        exit(1)

    # Establish connect to database
    db = cs50.SQL("sqlite:///students.db")

    ans = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first ASC", argv[1])

    for i in ans:
        if i["middle"] == None:
            print(i["first"], i["last"] + ", born", i["birth"])
        else:
            print(i["first"], i["middle"], i["last"] + ", born", i["birth"])


main()
