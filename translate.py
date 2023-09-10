from googletrans import Translator
import re
import os
from unidecode import unidecode

translator = Translator()

# Function to translate a text to French
def translate_to_french(text):
    translated = translator.translate(text, dest='fr')
    return translated.text

special_char_dict = {
    '«': '“',
    '»': '”',
    '"': '“',
    '–': '--',
    '\u200B': '',
    '°': 'o '
}

#WARINING: the order is important in the following dicts, as the plural
#words (e.g. TRAINERS) must appear before the singular words (e.g. TRAINER).
pokevocab_dict = {
    "TRAINERS": "DRESSEURS",
    "TRAINER": "DRESSEUR",
}

characters_dict = {
    "FLANNERY": "ADRIANE",
    "WINONA": "ALIZÉE",
    "LANETTE": "ANNETTE",
    "DRAKE": "ARAGON",
    "ARCHIE": "ARTHUR",
    "BRAWLY": "BASTIEN",
    "BRANDON": "BAYAR",
    "BRENDAN": "BRICE",
    "GRETA": "CAROLE",
    "ANABEL": "CATHY",
    "LUCY": "CHARLINE",
    "SIDNEY": "DAMIEN",
    "SPENSER": "ESTEBAN",
    "MAY": "FLORA",
    "GLACIA": "GLACIA",
    "DAN": "GUIDO",
    "JUAN": "JUAN",
    "TABITHA": "KELVIN",
    "TATE": "LÉVY",
    "TATIA": "LIZA",
    "MR. BRINEY": "M. MARCO",
    "JOSEPH STONE": "M. ROCHARD",
    "WALLACE": "MARC",
    "MATT": "MATTHIEU",
    "MAXIE": "MAX",
    "NORMAN": "NORMAN",
    "STEVEN STONE": "PIERRE ROCHARD",
    "STEVEN": "PIERRE",
    "PROFESSOR TAKAO COZMO": "PROFESSEUR KOSMO",
    "PROFESSOR COZMO": "PROFESSEUR KOSMO",
    "PROF. COZMO": "PROF. KOSMO",
    "COZMO": "KOSMO",
    "PROFESSOR BIRCH": "PROFESSEUR SEKO",
    "PROF. BIRCH": "PROF. SEKO",
    "BIRCH": "SEKO",
    "RYDEL": "RODOLPHE",
    "ROXANNE": "ROXANNE",
    "NOLAND": "SAM",
    "SHELLY": "SARAH",
    "SCOTT": "SCOTT",
    "PHOEBE": "SPECTRA",
    "TUCKER": "TAKIM",
    "WALLY": "TIMMY",
    "WATTSON": "VOLTÈRE"
}

places_dict = {
    "LITTLEROOT TOWN": "BOURG-EN-VOL",
    "OLDALE TOWN": "ROSYERES",
    "DEWFORD TOWN": "VILLAGE MYOKARA",
    "LAVARIDGE TOWN": "VERMILAVA",
    "FALLARBOR TOWN": "AUTEQUIA",
    "VERDANTURF TOWN": "VERGAZON",
    "PACIFIDLOG TOWN": "PACIFIVILLE",
    "PETALBURG CITY": "CLEMENTI-VILLE",
    "SLATEPORT CITY": "POIVRESSEL",
    "MAUVILLE CITY": "LAVANDIA",
    "RUSTBORO CITY": "MEROUVILLE",
    "FORTREE CITY": "CIMETRONELLE",
    "LILYCOVE CITY": "NENUCRIQUE",
    "MOSSDEEP CITY": "ALGATIA",
    "SOOTOPOLIS CITY": "ATALANOPOLIS",
    "EVER GRANDE CITY": "ETERNARA",
    "UNDERWATER": "FOND MARIN",
    "GRANITE CAVE": "GROTTE GRANITE",
    "MT. CHIMNEY": "MONT CHIMNEE",
    "SAFARI ZONE": "PARC SAFARI",
    "BATTLE FRONTIER": "ZONE DE COMBAT",
    "PETALBURG WOODS": "BOIS CLEMENTI",
    "RUSTURF TUNNEL": "TUNNEL MERAZON",
    "ABANDONED SHIP": "EPAVE",
    "NEW MAUVILLE": "NEW LAVANDIA",
    "METEOR FALLS": "SITE METEORE",
    "MT. PYRE": "MT. PYRE",
    "AQUA HIDEOUT": "PLANQUE AQUA",
    "SHOAL CAVE": "GROTTE TREFONDS",
    "SEAFLOOR CAVERN": "GROTTE MARINE",
    "VICTORY ROAD": "ROUTE VICTOIRE",
    "MIRAGE ISLAND": "ILE MIRAGE",
    "CAVE OF ORIGIN": "GROTTE ORIGINE",
    "SOUTHERN ISLAND": "ILE DU SUD",
    "FIERY PATH": "CHEMIN ARDENT",
    "JAGGED PASS": "SENTIER SINUROC",
    "SEALED CHAMBER": "SANCTUAIRE",
    "SCORCHED SLAB": "GROTTE ZENITH",
    "ISLAND CAVE": "GROTTE ISLAND",
    "DESERT RUINS": "RUINES DESERT",
    "ANCIENT TOMB": "TOMBEAU ANTIQUE",
    "INSIDE OF TRUCK": "CAMION",
    "SKY PILLAR": "PILIER CELESTE",
    "SECRET BASE": "BASE SECRETE",
    "PALLET TOWN": "BOURG PALETTE",
    "VIRIDIAN CITY": "VIRIDIAN CITY",
    "PEWTER CITY": "PEWTER CITY",
    "CERULEAN CITY": "CERULEAN CITY",
    "LAVENDER TOWN": "LAVENDER TOWN",
    "VERMILION CITY": "VERMILION CITY",
    "CELADON CITY": "CELADON CITY",
    "FUCHSIA CITY": "FUCHSIA CITY",
    "CINNABAR ISLAND": "CINNABAR ISLAND",
    "INDIGO PLATEAU": "INDIGO PLATEAU",
    "SAFFRON CITY": "SAFFRON CITY",
}

# Create characters_translation_dict using dictionary comprehension
characters_translation_dict = {translate_to_french(eng_name): fr_name for eng_name, fr_name in characters_dict.items()}
uni_characters_translation_dict = {unidecode(translate_to_french(eng_name)): fr_name for eng_name, fr_name in characters_dict.items()}
characters_translation_dict.update(uni_characters_translation_dict)

# Create places_translation_dict using dictionary comprehension
places_translation_dict = {translate_to_french(eng_name): fr_name for eng_name, fr_name in places_dict.items()}
uni_places_translation_dict = {unidecode(translate_to_french(eng_name)): fr_name for eng_name, fr_name in places_dict.items()}
places_translation_dict.update(uni_places_translation_dict)

# Create places_translation_dict using dictionary comprehension
pokevocab_translation_dict = {translate_to_french(eng_name): fr_name for eng_name, fr_name in pokevocab_dict.items()}
uni_pokevocab_translation_dict = {unidecode(translate_to_french(eng_name)): fr_name for eng_name, fr_name in pokevocab_dict.items()}
pokevocab_translation_dict.update(uni_pokevocab_translation_dict)

abreviations_dict = {
    'PROF.': 'PROFESSOR'
}

reverse_abreviations_dict = {
    'PROFESSEUR': 'PROF.'
}

def replace_abrevations(eng_text):
    new_eng_text = eng_text
    for abrv_name, full_name in abreviations_dict.items():
        new_eng_text = new_eng_text.replace(abrv_name, full_name)
    return(new_eng_text)

def replace_translation_mistakes(fr_text):
    """
    This needs to be modified if new names are traduced wrongfully. Really hard to do automatically without messing up
    because I can't even use capital letters as I want PROFESSOR to be traduced for example. For now, I do it manually.
    """
    new_fr_text = fr_text
    # Replace character names
    for eng_name, fr_name in characters_dict.items():
        new_fr_text = re.compile(re.escape(eng_name), re.IGNORECASE).sub(fr_name, new_fr_text)
        # new_fr_text = new_fr_text.replace(eng_name, fr_name)
    for eng_name, fr_name in characters_translation_dict.items():
        new_fr_text = re.compile(re.escape(eng_name), re.IGNORECASE).sub(fr_name, new_fr_text)
        # new_fr_text = new_fr_text.replace(eng_name, fr_name)

    # Replace place names
    for eng_name, fr_name in places_dict.items():
        new_fr_text = re.compile(re.escape(eng_name), re.IGNORECASE).sub(fr_name, new_fr_text)
        # new_fr_text = new_fr_text.replace(eng_name, fr_name)
    for eng_name, fr_name in places_translation_dict.items():
        new_fr_text = re.compile(re.escape(eng_name), re.IGNORECASE).sub(fr_name, new_fr_text)
        # new_fr_text = new_fr_text.replace(eng_name, fr_name)

    # Replace pokemon vocabulary names
    for eng_name, fr_name in pokevocab_dict.items():
        new_fr_text = re.compile(re.escape(eng_name), re.IGNORECASE).sub(fr_name, new_fr_text)
        # new_fr_text = new_fr_text.replace(eng_name, fr_name)
    for eng_name, fr_name in pokevocab_translation_dict.items():
        new_fr_text = re.compile(re.escape(eng_name), re.IGNORECASE).sub(fr_name, new_fr_text)
        # new_fr_text = new_fr_text.replace(eng_name, fr_name)

    # Replace special char names
    for eng_name, fr_name in special_char_dict.items():
        new_fr_text = new_fr_text.replace(eng_name, fr_name)

    # Process abréviations again
    for full_name, abrv_name in reverse_abreviations_dict.items():
        new_fr_text = re.compile(re.escape(full_name), re.IGNORECASE).sub(abrv_name, new_fr_text)
        # new_fr_text = new_fr_text.replace(full_name, abrv_name)

    return(new_fr_text)

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

def remove_curly_braces(word):
    # Remove characters within curly braces
    return ''.join(char for char in word if char not in '{}')
    
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
    cur_line_without_braces = ''
    lines = []
    # words = text.split(' ')
    # split where there is a space, but where the space is not for a string between brackets {}
    words = re.split(r'({[^}]*}|\s+)', text)
    words = "".join([item if item != " " else "STRINGTOBEREPLACED" for item in words])
    words = re.split('STRINGTOBEREPLACED', words)

    for word in words:
        len_cur_line = len(re.sub(r'{[^}]*}', 'XXXXXX', cur_line))
        len_word = len(re.sub(r'{[^}]*}', 'XXXXXX', word))
        if do_n:
            if len_cur_line + len_word + 1 <= box_limit:
                if cur_line:
                    cur_line += ' '  # Add a space between words
                cur_line += word
            else:
                # Start a new line with the word
                lines.append('\t' + '.string ' + '"' + cur_line + '\p' + '"' + '\n')
                cur_line = word
                do_n = False
        else:
            if len_cur_line + len_word + 1 <= mid_box_limit:
                if cur_line:
                    cur_line += ' '  # Add a space between words
                    cur_line_without_braces += ' '
                cur_line += word
            else:
                # Start a new line with the word
                lines.append('\t' + '.string ' '"'+ cur_line + '\\n' + '"' + '\n')
                cur_line = word
                do_n = True
    
    if cur_line:
        lines.append('\t' + '.string ' + '"'+cur_line+'"')
    
    return lines



count = 0
for subdir, dirs, files in os.walk('./'):
    for file_n in files:
        str_check = 'scripts.inc'
        if (file_n.endswith(str_check)) and (not file_n.endswith('eng.inc')):

            f = os.path.join(subdir, file_n)

            base_name_without_extension = os.path.splitext(file_n)[0]
            eng_file_name = base_name_without_extension + '_eng.inc'
            eng_file_path = os.path.join(subdir, eng_file_name)

            if os.path.exists(eng_file_path):
                print(f"Skipping {f} as {eng_file_name} already exists.")
                count += 1
                continue
                
            #MT: just for debug
            # if f != './data/maps/Route124_DivingTreasureHuntersHouse/scripts.inc':
            #     continue

            with open(f, 'r', encoding='utf-8') as file:
                lines = file.read().split('"')
            
            with open(f, 'r', encoding='utf-8') as file:
                orig_eng_text = file.read()

            #if no strings detected in the file, no need to calculate anything
            if len(lines) <= 1:
                count += 1
                continue

            eng_text = ''
            fr_lines = []
            on_a_text = False
            cur_section = ''
            #pattern = r'\{([^}]+)\}'

            fr_lines.append(lines[0][:-9])

            for idx, line in enumerate(lines):
                
                if idx != 0:
                    if (":\n\t.string " in lines[idx-1]) & (eng_text != "") :
                        # matches = re.findall(pattern, new_text)
                        pre_processed_eng_text = replace_abrevations(eng_text)
                        translated_text = translate_to_french(pre_processed_eng_text)
                        translated_text = replace_text_in_brackets(eng_text, translated_text)
                        translated_text = replace_translation_mistakes(translated_text)

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
                pre_processed_eng_text = replace_abrevations(eng_text)
                translated_text = translate_to_french(pre_processed_eng_text)
                translated_text = replace_text_in_brackets(eng_text, translated_text)
                translated_text = replace_translation_mistakes(translated_text)
                translated_text = add_line_breaks(translated_text)
                fr_lines = fr_lines + translated_text

            fr_text = "".join(fr_lines) +'\n'
            
            count += 1
            print('XXXXXXXXXXXXX')
            print(f)
            print(f'{count} files processed')

            #replace english text by french text
            with open(f, 'w', encoding='utf-8') as file:
                file.write(fr_text)

            #save english text in a new .inc file, just adding eng to it
            with open(eng_file_path, 'w', encoding='utf-8') as file:
                file.write(orig_eng_text)   


