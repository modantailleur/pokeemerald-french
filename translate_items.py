"""
This code is used to take only what's in common between the files eng_items.h and fr_items.h. It keeps
the same number of rows as in eng_items.h and translate what's inside 'name' by what it should be.
"""


import re

# Read the contents of item.h and items.h
with open('translate_folder/fr_items.h', 'r') as item_h_file:
    fr_items = item_h_file.read()

with open('translate_folder/eng_items.h', 'r') as items_h_file:
    eng_items = items_h_file.read()

eng_items_split = re.split(r'(?=\[ITEM_)', eng_items)
fr_items_split = re.split(r'(?=\[ITEM_)', fr_items)

# Initialize an empty dictionary to store the item mappings
item_dict = {}

pattern = r'\[([^]]+)\]\s*=\s*{([^}]+)\.name\s*=\s*_\("([^"]+)"'

# Iterate through the split parts and extract item mappings
for item_part in fr_items_split:
    match = re.search(pattern, item_part)
    if match:
        item_id = match.group(1)
        item_name = match.group(3)
        item_dict[item_id] = "\"" + item_name + "\""

cpt = 0

new_items = [eng_items_split[0]]

for item in eng_items_split[1:]:

    # Split by square brackets [] while keeping the brackets
    square_bracket_splits = re.split(r'(\[|\])', item)

    try:
        fr_item_correspondance = item_dict[square_bracket_splits[2]]
    except KeyError:
        fr_item_correspondance = None
    
    rest_of_text = square_bracket_splits[4]

    # Split by parentheses () while keeping the parentheses
    parentheses_splits = re.split(r'(\(|\))', rest_of_text)

    if fr_item_correspondance is not None:
        parentheses_splits[2] = fr_item_correspondance
    else:
        print(parentheses_splits[2][1:3])
        if parentheses_splits[2][1:3] == 'TM':
            parentheses_splits[2] = parentheses_splits[2].replace('TM', 'CT')
        if parentheses_splits[2][1:3] == 'HM':
            parentheses_splits[2] = parentheses_splits[2].replace('HM', 'CS')

    new_rest_of_text = "".join(parentheses_splits)
    square_bracket_splits[4] = new_rest_of_text
    new_square_bracket_splits = "".join(square_bracket_splits)

    new_items.append(new_square_bracket_splits)

new_items = "".join(new_items)

#replace english text by french text
with open('translate_folder/items.h', 'w', encoding='utf-8') as file:
    file.write(new_items)