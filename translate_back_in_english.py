import os

count = 0
for subdir, dirs, files in os.walk('./'):
    for file_n in files:
        str_check = 'scripts.inc'
        if (file_n.endswith(str_check)) and (not file_n.endswith('eng.inc')):
            f = os.path.join(subdir, file_n)

            base_name_without_extension = os.path.splitext(file_n)[0]
            eng_file_name = base_name_without_extension + '_eng.inc'
            eng_file_path = os.path.join(subdir, eng_file_name)

            if not os.path.exists(eng_file_path):
                print(f"Skipping {f} as {eng_file_name} doesn't exist.")
                count += 1
                continue

            with open(eng_file_path, 'r', encoding='utf-8') as file:
                orig_eng_text = file.read()

            with open(f, 'w', encoding='utf-8') as file:
                file.write(orig_eng_text)

            os.remove(eng_file_path)
            
            count += 1
            print('XXXXXXXXXXXXX')
            print(f)
            print(f'{count} files processed')