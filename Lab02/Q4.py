def first_occurrence(arr, target):
    left, right = 0, len(arr) - 1
    result = -1

    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == target:
            result = mid
            right = mid - 1 
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return result

def last_occurrence(arr, target):
    left, right = 0, len(arr) - 1
    result = -1

    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == target:
            result = mid
            left = mid + 1
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return result

def binary_search_deluxe(array, target):
    last = last_occurrence(array, target)
    first = first_occurrence(array, target)
    return [first, last]

print(binary_search_deluxe([1, 2, 3, 10, 10, 10, 12, 12], 10))