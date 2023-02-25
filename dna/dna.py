from csv import reader, DictReader
import cs50
from sys import argv

#Checks for command line arguement count
if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)
    
#read dna seq file
with open(argv[2]) as dnafile:
    dnareader = reader(dnafile)
    for row in dnareader:
        dnalist = row
        
#List of the sequence
dna = dnalist[0]
#dictionary stores the sequences
sequences = {}

#read CSV file for genes
with open(argv[1]) as p:
    person = reader(p)
    for row in person:
        dnaseq = row
        dnaseq.pop(0)
        break
        

#genes are key in dict
for seq in dnaseq:
    sequences[seq] = 1
        
for k in sequences:
    l = len(k)
    tMax = 0
    temp = 0
    for i in range(len(dna)):
        while temp > 0:
            temp -= 1
            continue
        
        if dna[i: i + l] == k:
            while dna[i - l :i] == dna[i: i + l]:
                temp += 1
                i += l
            
            if temp > tMax:
                tMax = temp
                
    sequences[k] += tMax

with open(argv[1], newline='') as peopleF:
    people = DictReader(peopleF)
    for person in people:
        match = 0
        for d in sequences:
            if sequences[d] == int(person[d]):
                match += 1
        if match == len(sequences):
            print(person['name'])
            exit()
            
    print("No match")