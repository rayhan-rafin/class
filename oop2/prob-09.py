s = "ChatGPT is an artificial intelligence chatbot developed by OpenAland launched in November 2022. It is built on top of OpenAI's GPT-3 family of large language models and has been fine-tuned  (an approach to transfer learning) using both supervised and reinforcement learning techniques."
word_list = s.split()
unq_word = set(word_list)
print(unq_word)

for i in unq_word:
    print("frequency of", i, "is: ", word_list.count(i))
