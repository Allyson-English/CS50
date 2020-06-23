from sys import argv, exit
import csv
import re
import collections


def main():

    if len(argv) != 3:
        print("Usage Error: three command line arguments (.py .csv, .txt) required")
        exit(1)

    # Open .TXT file containing genetic sequence for unknown character
    sequence_file = open(argv[2], "r")
    sequence = sequence_file.read()

    # Open .CSV file containing genetic sequence information for each character
    with open(argv[1], "r") as genetic_db:
        reader = csv.reader(genetic_db)

    # Read the column headers into the dictionary to establish patterns that will be examined
    # Set values for each dictionary key equal to zero

        i = 1
        # seq_counts = {}
        seq_counts = collections.OrderedDict()
        for colnams in reader:
            while i < len(colnams):
                if colnams[0] == "name":
                    seq_counts[colnams[i]] = 0
                    i += 1

    # Iterate through substrings stored as dictionary keys to count how many times each substring appears in the genetic sequence
    # longest sequential substring count is added as dictionary value associated with key
    eval_strepeats(sequence, seq_counts)

    input_file = csv.DictReader(open(argv[1]))

    for row in input_file:
        temp_dict = collections.OrderedDict()
        for pos in row:
            if pos != "name":
                temp_dict[pos] = int(row[pos])

        if temp_dict == seq_counts:
            print(row["name"])
            return

    print("No match")





def eval_strepeats(full_string, nucleotide_sequences=dict):
    
    for i in nucleotide_sequences:
        groups = re.findall(r'(?:{})+'.format(i), full_string)
        largest = 0
        for j in groups:
            l = len(j) / len(i)
            if nucleotide_sequences[i] < l:
                nucleotide_sequences[i] = l


main()
