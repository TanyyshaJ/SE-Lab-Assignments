class string_ops:
    def __init__(self, s):
        self.s = s

    def split_sentence(self):
        split_values = []
        temp = ""
        for char in self.s:
            if char == " ":
                split_values.append(temp)
                temp = ""
            
            else:
                temp += char

        if temp:
            split_values.append(temp)

        return split_values
    
    def longest_word(self):
        max = 0
        sent_list = self.split_sentence()
        for word in sent_list:
            if len(word) > max:
                max = len(word)
                longest_word = word

        print(f"{longest_word} is the longest word of length = {max}")

    def freq_char(self, char):
        count = 0
        n = len(char)
        if n == 1:
            for i in range(len(self.s)):
                if self.s[i].lower == char:
                    count+=1
            print(f"Frequency of {char} is {count}")

        else:
            words = self.split_sentence()
            for word in words:
                if word == char:
                    count+=1
            print(f"Frequency of {char} is {count}")

    def palindrome(self):
        words = self.split_sentence()
        word_str = "".join(words)
        rev_str = word_str[::-1]

        if word_str == rev_str:
            print("It is a palindrome")

        else:
            print("Not a palindrome")

    def occur_sub(self, sub):
        words = self.split_sentence()
        index = -1
        for i in range(len(words)):
            if words[i] == sub:
                index = i
                break
        if index == -1:
            print(f"{sub} does not occur in the sentence")

        else:
            print(f"{sub} found at {index} in the sentence")

    def freq_words(self):
        words = self.split_sentence()
        dict = {}

        for i in range(len(words)):
            if words[i] in dict.keys:
                dict[words[i]]+=1
            else:
                dict[words[i]] = 1
        
        print(dict)

sentence = input("Enter the string: ")
obj = string_ops(sentence)
flag = True

while(flag):
    print("----MENU----")
    print("1. Longest Word")
    print("2. Frequency of character")
    print("3. Check if Palindrome")
    print("4. First appearance of substring")
    print("5. Frequency of each word")
    print("6. EXIT")
    op = int(input("Select an option: "))

    if op == 1:
        long_word_sent = obj.longest_word()

    elif op == 2:
        char = input("Enter the character whose frequency of occurrence you want: ")
        frequency_of_char =  obj.freq_char(char)

    elif op == 3:
        sent_string = obj.palindrome()

    elif op == 4:
        sub_string = input("Enter the substring whose first appearance you want to know: ")
        freq = obj.occur_sub(sub_string)

    elif op == 5:
        word_freq = obj.freq_words()

    elif op == 6:
        flag = False

    else:
        print("Invalid option!")