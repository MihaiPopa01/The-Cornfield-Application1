def partition(vector, left, right):
    i = (left - 1)
    pivot = vector[right]

    for j in range(left, right):
        if vector[j] <= pivot:
            i = i + 1
            vector[i], vector[j] = vector[j], vector[i]

    vector[i + 1], vector[right] = vector[right], vector[i + 1]
    return (i + 1)


def quick_sort(vector,  left, right):
    if left < right:
        pi = partition(vector, left, right)
        quick_sort(vector, left, pi - 1)
        quick_sort(vector, pi + 1, right)

