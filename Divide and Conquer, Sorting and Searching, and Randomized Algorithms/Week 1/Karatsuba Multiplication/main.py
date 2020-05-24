def karatsubamult(x, y):
    if(len(str(x)) == 1 or len(str(y)) == 1):
        return x*y
    else:
        n = max(len(str(x)), len(str(y)))
        nby2 = n // 2
        a = x // (10 ** nby2)
        b = x % (10 ** nby2)
        c = y // (10 ** nby2)
        d = y % (10 ** nby2)
        ac = karatsubamult(a, c)
        bd = karatsubamult(b, d)
        ad_plus_bc = karatsubamult(a + b, c + d) - ac - bd

        return ac * 10 ** (nby2 * 2) + (ad_plus_bc * 10 ** nby2) + bd



def main():
    first_number = 3141592653589793238462643383279502884197169399375105820974944592
    second_number = 2718281828459045235360287471352662497757247093699959574966967627
    result = karatsubamult(first_number, second_number)
    print(result)


if __name__ == "__main__":
    main()