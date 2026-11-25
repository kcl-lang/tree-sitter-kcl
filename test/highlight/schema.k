schema Person:
#^ @keyword.type
#        ^ type
    age: int = 33
    # ^ variable
    #     ^ type.builtin
    #          ^ number

schema Employee(Person):
#^ @keyword.type
#        ^ type
#               ^ type
    salary: float = 1000.0
    # ^ variable
    #       ^ type.builtin
    #               ^ number.float

protocol DataProtocol:
#^ @keyword.type
#         ^ type
    data: str
    # ^ variable
    #     ^ type.builtin

weather = "sunny"
day = "wednesday"

rule IsSunny:
#^ @keyword.type
#      ^ type
    weather == "sunny"
    # ^ variable
    #       ^ operator
    #            ^ string

rule IsWednesday:
    day == "wednesday", "today is not wednesday"
    # ^ variable
    #   ^ operator
    #         ^ string
    #                     ^ string

rule Main(IsSunny, IsWednesday):
#^ @keyword.type
#      ^ type
#           ^ type
#                   ^ type
    id == 1

@deprecated
#   ^ attribute
schema Person:
    age: int

@deprecated(version="1.16", reason="use firstName and lastName instead", strict=True)
#   ^ attribute
#             ^ variable
#                     ^ string
schema Person:
    age: int