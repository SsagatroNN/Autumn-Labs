def mergesort(X):
    if len(X)<=1:
        return X
    mid = len(X)//2
    L = mergesort(X[:mid])
    R = mergesort(X[mid:])
    out = []
    i = j = 0
    while i<len(L) or j<len(R):
        if i==len(L):
            out.append(R[j])
            j += 1
        elif j==len(R):
            out.append(L[i])
            i += 1
        else:
            l = L[i]
            r = R[j]
            if l<r:
                out.append(L[i])
                i += 1
            else:
                out.append(R[j])
                j += 1
    return out
    
mergesort([6, 5, 3, 1, 8, 7, 2, 4])