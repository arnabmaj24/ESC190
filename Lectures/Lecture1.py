
#deep copy of arbitrary lists

L = [[[1,2], 5], 2]

#shallow copy
L2 = L[:] # same as L.copy()

#shallow coppy creates new list, L and l2 have diff memeory adresses
#but L2 and L are aliases
#changing L[0] is not the same as changing L2[0]
#but, L[0][0] = L2[0][0] = 3, they both are changed

#if i can make a deep copy of simple lists, can i with complicated lists?

#to crate a deep copy of list L
#make L2 = [deepcopy(L[0]), deeepcopy(L[1])....]

def deeepcopy(L):

    """ Return deep copy of L """

    if type(L) != list:
        return L

    res = []
    for e in L:
        if type(e) == list:
            res.append(deeepcopy(e))
        else:
            res.append(deeepcopy(e))
    return res

#-----------------------------------------------------------------------------

alhpabet = "abcdefg"

for letter in alhpabet:
    for letter2 in alhpabet:
        for letter3 in alhpabet:
            # print(letter+letter2+letter3)
#what if want to list k length strings from alpha

def all_strings(k, alhpabet):

    res = []
    if k == 0:
        return [""]

    all_k1_string = all_strings(k-1, alhpabet)
    for string in all_k1_string:
        res.append(letter+string)
    return res
        
#complexity of O(n^k)
        


