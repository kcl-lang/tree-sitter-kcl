import regex
# ^ keyword.import
#        ^ module

import regex.v1
# ^ keyword.import
#        ^ module
#            ^ module

import regex as rxp
# ^ keyword.import
#        ^ module
#            ^ keyword.import
#                ^ module

import regex.v1 as rxp
# ^ keyword.import
#        ^ module
#               ^ keyword.import
#                   ^ module

import ...regex
# ^ keyword.import
#           ^ module