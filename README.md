WORK IN PROGRESS, THIS REPO IS NOT READY NOW

# Pokémon Emerald French

## Introduction

This is a propostion of translation for the original pokeemerald repo [https://github.com/pret/pokeemerald]. If you want to use the same installation procedure as in this repo, please rename the directory 'pokeemerald-french' in 'pokeemerald' after git cloning this repo. 

Another repository has tried to translate pokeemerald in french: [https://github.com/yopox/pokeemerald-fr]. The problem is that it is 795 commits behind to this date, and that it didn't translate the scripts (only attacks, locations, natures, abilities and pokemon names). Here, instead of translating every script manually, we'll propose an automatic translator based on google translate. As this method can lead to weird translating behaviors, we'll also modify manually the main scripts. The scripts will never be the same as the original one, obviously, but at least they are understandable for french speakers, and close enough to the original one to follow the story.

## Translation information

The files pokedex_text.h and species_names.h have been created using [https://github.com/BenchBadr/PokeemeraldTranslation] tool. As this tool didn't work exactly as expected (too many Pokémons for the original repo), I've modified a little bit the two files to delete the extra Pokémons.

The constants in "strings.c" have been translated with chat gpt (and some manual modifications). The locations names, attacks names, natures names, and abilities names are taken from the repo [https://github.com/yopox/pokeemerald-fr].

The scripts within the folder 'maps' have been translated using the python script translate.py, which uses google translate to automatically translate all the text. Some text have been modified manually afterwards.

# Pokémon Emerald

This is a decompilation of Pokémon Emerald.

It builds the following ROM:

* [**pokeemerald.gba**](https://datomatic.no-intro.org/index.php?page=show_record&s=23&n=1961) `sha1: f3ae088181bf583e55daf962a92bb46f4f1d07b7`

To set up the repository, see [INSTALL.md](INSTALL.md).


## See also

Other disassembly and/or decompilation projects:
* [**Pokémon Red and Blue**](https://github.com/pret/pokered)
* [**Pokémon Gold and Silver (Space World '97 demo)**](https://github.com/pret/pokegold-spaceworld)
* [**Pokémon Yellow**](https://github.com/pret/pokeyellow)
* [**Pokémon Trading Card Game**](https://github.com/pret/poketcg)
* [**Pokémon Pinball**](https://github.com/pret/pokepinball)
* [**Pokémon Stadium**](https://github.com/pret/pokestadium)
* [**Pokémon Gold and Silver**](https://github.com/pret/pokegold)
* [**Pokémon Crystal**](https://github.com/pret/pokecrystal)
* [**Pokémon Ruby and Sapphire**](https://github.com/pret/pokeruby)
* [**Pokémon Pinball: Ruby & Sapphire**](https://github.com/pret/pokepinballrs)
* [**Pokémon FireRed and LeafGreen**](https://github.com/pret/pokefirered)
* [**Pokémon Mystery Dungeon: Red Rescue Team**](https://github.com/pret/pmd-red)
* [**Pokémon Diamond and Pearl**](https://github.com/pret/pokediamond)
* [**Pokémon Platinum**](https://github.com/pret/pokeplatinum) 
* [**Pokémon HeartGold and SoulSilver**](https://github.com/pret/pokeheartgold)
* [**Pokémon Mystery Dungeon: Explorers of Sky**](https://github.com/pret/pmd-sky)

## Contacts

You can find us on:

* [Discord (PRET, #pokeemerald)](https://discord.gg/d5dubZ3)
* [IRC](https://web.libera.chat/?#pret)
