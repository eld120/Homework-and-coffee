import csv
from sys import argv
from itertools import groupby

userInput = argv[1] #database/csv file
seqInput = argv[2]  #string of dna sequence
dataBase = []   #full length of DNA string
dna_library = [] #list of dicts
keyz = []

#opens user database of name/sequence 
with open(userInput, 'r') as csv_file:
    csv_reader = csv.DictReader(csv_file)
    
    keyz = csv_reader.fieldnames
    #saves data into list of dicts
    for line in csv_reader:
        dna_library.append(line)

#counts sequence repetition in a text file
with open(seqInput, 'r') as seq_file:
    x = seq_file.read()
    dataBase.append(x)

# returns highest number or consequtive key matches
#a dict of keys and the highest consecutive count of matches
zmatches = {}
def zfind_matches(keyz, dataBase):
    for key in keyz:
        match_count = 0
        zmatches[key] = 0
        data_length = len(key)
        #compare = []
        i = 0
        while i < (len(dataBase[0])):
            zstring = dataBase[0]
            zeta = zstring[0 + i: i + data_length] #normal substring
            xeta = zstring[0 + i + data_length: i  + 2 * data_length] #substring + 1
            yeta = zstring[i - data_length : i ] #substring - 1

            if i == (len(zstring) - data_length + 1):
                i += 1
                continue
            elif zeta == key and yeta == key:
                match_count += 1
                i += data_length
            elif zeta == key:
                if match_count == 0:
                    match_count += 1
                i += data_length
            else:
                if zmatches[key] < match_count:
                        zmatches[key] = match_count
                match_count = 0
                i +=1
    #print(zmatches)  
    return(zmatches) 

zfind_matches(keyz, dataBase)

def zfindUser(zmatches, dna_library):
    '''
    Dict, list of dDict -> String
    returns the name of the user in the 2nd dict that 
    matches all values in the first dict
    '''
    matches = []

    #gets correct lookup values into array

    for seq in keyz:
        
        matches.append(str(zmatches[seq]))
    matches = matches[1:]    
    #input all dict values into array
    inntertable = []
    answertable = []

    for i in range(len(dna_library)):
        for uiu in dna_library[i]:
            inntertable.append(dna_library[i][uiu])
        answertable.append(inntertable)
        inntertable = []
    #print(answertable)
    #print(matches)
    
    for i in range(len(answertable)):
        metatable = answertable[i]
        metatable = metatable[1:]
        #print(metatable)
        if matches == metatable:
            print(dna_library[i]['name'])
            break
        elif i == (len(answertable) -1):
            print('No match')
        else:
            continue
            
    


                
zfindUser(zmatches, dna_library)

    
            