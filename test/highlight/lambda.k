lambda fullname: Person, lastname {
# ^ keyword.function
#        ^ variable.parameter
#                 ^ type
#                          ^ variable.parameter
    x.name + " " + str(lastname)
    # <- variable
    #  ^ property
    #        ^ string
    #               ^ function.call
    #                     ^ variable
}

lambda { fullname: Person, lastname } -> Person {
# ^ keyword.function
#          ^ variable.parameter
#                   ^ type
#                           ^ variable.parameter
#                                        ^ type
    x.name + " " + str(lastname)
    # <- variable
    #  ^ property
    #        ^ string
    #               ^ function.call
    #                     ^ variable
}
