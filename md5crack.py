from hashlib import md5
from sys import exit
import argparse, time

parser = argparse.ArgumentParser(
    description='\
        Simple MD5 dictionary-attack decryption tool.'
)
parser.add_argument (
    'HASHFILE',
    type=str,
    help='A file with the hashes to be cracked, seperated by newlines.'
)
parser.add_argument(
    'DICTIONARY',
    type=str,
    help='The dictionary file to use.'
)
args = parser.parse_args()

def get_file_as_list(path):
    try:
        file = open(path)
    except:
        print('Could not open file at given path.')
        exit()
    else:
        lst = file.read().split('\n')
        file.close()
        # Remove empty lines
        while('' in lst): lst.remove('')
    return lst

hashes = get_file_as_list(args.HASHFILE)
print('Number of hashes to test: ' + str(len(hashes)))

dictionary = get_file_as_list(args.DICTIONARY)
print('Number of words in dictionary: ' + str(len(dictionary)) + '\n')

start_time = time.time()
print('Starting on ' + time.ctime(start_time) + '\n')

found = 0
i = 0
for word in dictionary:
    i += 1
    try:
        md5hash = md5(word.encode('ascii')).hexdigest()
    except UnicodeEncodeError:
        print('Invalid dictionary entry: ' + word)
    else:
        if md5hash in hashes:
            print(word+'::'+md5hash)
            found += 1

    if found == len(hashes): 
        print('All hashes found.')
        break

end_time = time.time()
print('\nFinished on ' + time.ctime(end_time))
print('Time taken: %i seconds' % (end_time - start_time))
print('Words hashed: %i' % i)
print('Valid hashes found: %i' % found)