# magic square game
# def magic(n):
#     arr = []
#     for i in range(n):
#         temp = []
#         for j in range(n):
#             temp.append(0)
#         arr.append(temp)

#     print(arr)
#     # now first 1 ko place pkda do
#     x = int(n/2)
#     y = n-1
#     arr[x][y] = 1
#     x -= 1
#     y += 1
#     count = 1
#     while (count < n*n):

#         if (x == -1 and j == n):
#             x = 0
#             y = n-2

#         x += n
#         y += n
#         x %= n
#         y %= n

#         if (arr[x][y] != 0):
#             x += 1
#             y -= 2

#         else:

#             count += 1
#             arr[x][y] = count
#             x -= 1
#             y += 1

#     print(arr)


# n=int(input("Enter the size of magic square : "))
# magic(n)

# dobble game code
import speech_recognition as sr
import string
import random
symbols = []
symbols = list(string.ascii_letters)
print(symbols)
card1 = [0]*5
card2 = [0]*5
print(card1)
print(card2)

pos1 = random.randint(0, 4)
pos2 = random.randint(0, 4)

print(pos1, " and ", pos2)

samesymbol = random.choice(symbols)
symbols.remove(samesymbol)
if (pos1 == pos2):
    card2[pos1] = samesymbol
    card1[pos1] = samesymbol
else:
    card1[pos1] = samesymbol
    card2[pos2] = samesymbol
    card1[pos2] = random.choice(symbols)
    symbols.remove(card1[pos2])
    card2[pos1] = random.choice(symbols)
    symbols.remove(card2[pos1])

print(card1)
print(card2)

i = 0
while (i < 5):
    if (i != pos1 and i != pos2):
        alphabet1 = random.choice(symbols)
        symbols.remove(alphabet1)
        alphabet2 = random.choice(symbols)
        symbols.remove(alphabet2)
        card1[i] = alphabet1
        card2[i] = alphabet2
    i += 1

print(card1)
print(card2)

# simple program to generate dobble cards which have only one element common

# '''
# This is a sentence
# '''

# generating a pyramid
# n = int(input("Enter the size of the pyramid"))

# curr = 1
# end = 1

# for i in range(n-1, -1, -1):
#     print(" "*(i), end="")
#     for j in range(curr, end+1):
#         print(j, end="")
#     for j in range(end-1, curr-1, -1):
#         print(j, end="")
#     curr += 1
#     end += 2
#     print()

# speech recognition
import speech_recognition as sr

AUDIO_FILE=("Conference.wav")

r=sr.Recognizer()

with sr.AudioFile(AUDIO_FILE) as source:
    audio=r.record(source)

try:
    print("Audio File Contains -> "+r.recognize_google(audio))
except sr.UnknownValueError:
    print("WTF")
except sr.RequestError:
    print("NO results")