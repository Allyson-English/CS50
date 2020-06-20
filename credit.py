def main():

    user_input = input("Number: ")

    cc_number = cc_array(user_input)

    csum = check_sum(cc_number)

    validation_test = is_cc(csum, cc_number)

    print(validation_test)


def cc_array(u_input):

    cc_len = len(u_input)

    creditcard = []

    for i in range(0, cc_len):
        creditcard.append(u_input[i])
        i += 1

    return creditcard


def check_sum(cc_numarray):
    trav_s = len(cc_numarray)-1
    trav_p = len(cc_numarray)-2

    s = 0
    p = 0

    while trav_s >= 0:
        s += int(cc_numarray[trav_s])
        trav_s -=2

    while trav_p >= 0:
        temp = int(cc_numarray[trav_p])*2
    #     print(cc_numarray[trav_p])
        f_dig = int(temp / 10)
        s_dig = int(temp % 10)
        p += f_dig + s_dig
    #     print("First digit: ", f_dig, "Second digit: ", s_dig)
        trav_p -= 2

    cs = p+s

    return cs


def is_cc(cs, arr):

    if cs % 10 == 0:
        if len(arr) == 13:
            if int(arr[0]) == 4:
                return "VISA"
        if len(arr) == 15:
            if (int(arr[0])) == 3:
                if (int(arr[1])) == 4 or (int(arr[1])) == 7:
                    return "AMEX"
        if len(arr) == 16:
            if (int(arr[0])) == 5:
                if (int(arr[1])) >= 1 or (int(arr[1])) <= 5:
                    return "MASTERCARD"
            if (int(arr[0])) == 4:
                return "VISA"

    else:
        return "INVALID"


main()
