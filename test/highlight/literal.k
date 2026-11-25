33
# <- number

3.14
# <- number.float

"all"
# <- string

{
    key = value
    # <- variable
    #   ^ operator
    #       ^ variable
}

"Value: ${1+2: #yaml}!"
# <- string
#       ^ punctuation.special
#          ^ operator
#                   ^ punctuation.special
#                    ^ string
