# ft_db
ft_db is a collaborative project between David Huang and Yangyang Herrera. It has all basic database functions. It is written purely in `C`

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
