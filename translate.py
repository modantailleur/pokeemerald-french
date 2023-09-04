from googletrans import Translator
import re


def replace_character_names(fr_text):
    """
    This needs to be modified if new names are traduced wrongfully. Really hard to do automatically without messing up
    because I can't even use capital letters as I want PROFESSOR to be traduced. For now, I do it manually.
    """
    modified_string = fr_text.replace("BOULEAU", "BIRCH")
    modified_string = modified_string.replace('«', '“')
    modified_string = modified_string.replace('»', '”')
    return(modified_string)

def replace_text_in_brackets(eng_text, fr_text, pattern=r'\{([^}]+)\}', regex = r'(?<=\{).*?(?=\})'):
    """
    This function is used to replace the text that is inside the brackets in the french translation,
    and that should remain the same as the english version as it is just a variable (for example {PLAYER} that could wrongfuly be translated
    in {JOUEUR})
    """
    matches = re.findall(pattern, eng_text)
    fr_text_mod = fr_text
    fr_text_split = re.split(r'(\{[^}]+\})', fr_text_mod)
    fr_text_split = [element.replace("\xa0", " ") for element in fr_text_split]
    idx_brackets = [k for k in range(len(fr_text_split)) if '{' in fr_text_split[k] ]
    for idx, element in enumerate(matches):
        fr_text_split[idx_brackets[idx]] = re.sub(regex, element, fr_text_split[idx_brackets[idx]], 1)
    fr_text_mod = "".join(fr_text_split)
    return(fr_text_mod)

def add_line_breaks(text, mid_box_limit=35, box_limit=35):
    """
    Add line breaks (\p and \n) to the text based on character and line limits.

    Args:
    text (str): The input text.
    char_limit (int): The character limit for adding \p.
    line_limit (int): The line limit for adding \n.

    Returns:
    list: The formatted text in the form of a list.
    """

    do_n = False
    cur_line = ''
    lines = []
    words = text.split(' ')

    for word in words:
        if do_n:
            if len(cur_line) + len(word) + 1 <= box_limit:
                if cur_line:
                    cur_line += ' '  # Add a space between words
                cur_line += word
            else:
                # Start a new line with the word
                lines.append('\t' + '.string ' + '"' + cur_line + '\\n' + '"' + '\n')
                cur_line = word
                do_n = False
        else:
            if len(cur_line) + len(word) + 1 <= mid_box_limit:
                if cur_line:
                    cur_line += ' '  # Add a space between words
                cur_line += word
            else:
                # Start a new line with the word
                lines.append('\t' + '.string ' '"'+ cur_line + '\p' + '"' + '\n')
                cur_line = word
                do_n = True
    
    if cur_line:
        lines.append('\t' + '.string ' + '"'+cur_line+'"')
    
    return lines

translator = Translator()

# Function to translate a text to French
def translate_to_french(text):
    # translator = Translator()
    translated = translator.translate(text, dest='fr')
    return translated.text

# Read the input file and split it by double quotes
with open('/home/modantailleur/Documents/pokeemerald-fr-bbs/pokeemerald/scripts.inc', 'r', encoding='utf-8') as file:
    # lines = file.read().split('.string ')
    lines = file.read().split('"')
    # lines = file.read()

eng_text = ''
fr_lines = []
on_a_text = False
cur_section = ''
#pattern = r'\{([^}]+)\}'

fr_lines.append(lines[0][:-9])

# for idx, line in enumerate(lines):
#     if line[-8:] == ".string ":
#         cur_data = lines[idx+1]
#         cur_data = cur_data.replace('\p', ' ').replace('\l', ' ').replace('\\n', ' ')
#         eng_text = eng_text+cur_data
    
#     if idx+1 < len(lines):
#         if ":\n\t.string " in lines[idx+1]:
#             # matches = re.findall(pattern, new_text)
#             translated_text = translate_to_french(eng_text)
#             translated_text = replace_text_in_brackets(eng_text, translated_text)
#             translated_text = add_line_breaks(translated_text)
#             eng_text = ''
#             fr_lines.append(translated_text)
#         else:
#             fr_lines.append(lines[idx+1])

for idx, line in enumerate(lines):
    
    if idx != 0:
        if (":\n\t.string " in lines[idx-1]) & (eng_text != "") :
            # matches = re.findall(pattern, new_text)
            translated_text = translate_to_french(eng_text)
            translated_text = replace_text_in_brackets(eng_text, translated_text)
            translated_text = replace_character_names(translated_text)
            translated_text = add_line_breaks(translated_text)
            fr_lines = fr_lines + translated_text
            fr_lines.append(cur_section)
            eng_text = ''

        if lines[idx-1][-8:] == ".string ":
            cur_data = lines[idx]
            cur_data = cur_data.replace('\p', ' ').replace('\l', ' ').replace('\\n', ' ')
            eng_text = eng_text+cur_data

        else:
            if ".string " in lines[idx]:
                if lines[idx][1] == '\n':
                    cur_section = lines[idx][:-9]

if eng_text:
    translated_text = translate_to_french(eng_text)
    translated_text = replace_text_in_brackets(eng_text, translated_text)
    translated_text = add_line_breaks(translated_text)
    fr_lines = fr_lines + translated_text


fr_text = "".join(fr_lines)

# Open the file in write mode and save the text
with open("pokeemerald/myexample.inc", 'w') as file:
    file.write(fr_text)








# print(len(lines))
# print(lines)
# # Initialize an empty list to store translated lines
# translated_lines = []

# # Flag to determine if we are inside brackets
# inside_brackets = False

# for line in lines:
#     # Check if the line is inside brackets
#     if inside_brackets:
#         translated_line = translate_to_french(line)
#         translated_lines.append('"' + translated_line + '"')
#     else:
#         translated_lines.append(line)
    
#     inside_brackets = not inside_brackets

# # Join the translated lines back together
# result = ''.join(translated_lines)

# # Write the result back to the file
# with open('script.inc', 'w', encoding='utf-8') as file:
#     file.write(result)

# print("Translation and replacement completed successfully.")
