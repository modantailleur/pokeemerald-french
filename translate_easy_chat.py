"""
This code is used to take only what's in common between the files eng_items.h and fr_items.h. It keeps
the same number of rows as in eng_items.h and translate what's inside 'name' by what it should be.
"""


import re
import os 
from googletrans import Translator

translator = Translator()

# Function to translate a text to French
def translate_to_french(text):
    translated = translator.translate(text, dest='fr')
    return translated.text

for subdir, dirs, files in os.walk('./src/data/easy_chat/'):
    for file_n in files:
        if file_n not in ["easy_chat_groups.h", "easy_chat_words_by_letter.h", "easy_chat_group_move_1.h", "easy_chat_group_move_2.h", "easy_chat_group_pokemon.h", \
                          "easy_chat_group_pokemon2.h", "easy_chat_group_trainer.h"]:
            f = os.path.join(subdir, file_n)

            base_name_without_extension = os.path.splitext(file_n)[0]
            eng_file_name = base_name_without_extension + '_eng.inc'
            eng_file_path = os.path.join(subdir, eng_file_name)
            
            # Read the contents of item.h and items.h
            with open(f, 'r') as easy_file:
                easy_item = easy_file.read()
            # Use re.findall to split the content by the character '"' while preserving the '"'
            # easy_item_split = re.findall(r'(?:[^"]*"[^"]*")|(?:[^"]*)', easy_item)
            # easy_item_split = [s for s in easy_item_split if s.strip() != '']
            easy_item_split = easy_item.split('"')


            if len(easy_item_split) > 1:
                for i in range(1, len(easy_item_split), 2):  # Loop through even numbers from 0 to 8
                    easy_item_split[i] = '"' + translate_to_french(easy_item_split[i]).upper() + '"'
                to_save = "".join(easy_item_split)
                with open(f, 'w', encoding='utf-8') as file:
                    file.write(to_save)  
