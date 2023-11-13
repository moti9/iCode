def main():
    list1 = ["Moti", "Kumar", "Yadav"]
    print("Length of the list : ", len(list1))

    list2 = [1, 2, 3, 4, 5]
    print("Type : ", type(list2))

    # list constructor
    list3 = list(("Moti", "Vasu"))  # Use double round bracket
    print("List is : ", list3)

    print(list1[1:2])
    print(list2[1:])
    print(list3[:4])


if __name__ == "__main__":
    main()
