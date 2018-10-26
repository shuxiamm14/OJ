while True:
    try:
        string=input()
        for i in string:
            res=bin(ord(i)).replace("0b","").rjust(8,"0")
            print("1"+res[1:] if res.count("1")%2==0 else res)

    except:
        break
