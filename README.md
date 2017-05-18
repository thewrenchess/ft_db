# ft_db
ft_db is a self-made database. It demonstrates abilities to not only creating and destroying persistent database and tables, but also adding, sorting, and removing entries.

## Installation
1. Dowload this repository to your local file
2. `make`

## Usage
`./ft_db`

## Note
All databases and tables are created under the `db` folder

## Known Bugs
- Since all memories are statically allocated, there is a possibility to get an error statement when more than the allocated limit is entered.
- Entering wrong types of data will result in `0` being stored into file
