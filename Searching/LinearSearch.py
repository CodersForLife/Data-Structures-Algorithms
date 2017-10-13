def linearSearch(list, targetValue):

    for i in range(len(list)):
        if (targetValue == list[i]):
            return i
    return "Not Found"

def main():

    # Example
    exampleList = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    exampleTarget = 5
    result = linearSearch(exampleList, exampleTarget)
    if (result == "Not Found"):
        print("Your value", exampleTarget, "was", result)
    else:
        print("Your value", exampleTarget, "was found at list index", result)

main()
