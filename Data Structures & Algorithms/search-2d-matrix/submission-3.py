class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        #ayyy i did this one all by my lonesome
        rowLow = 0
        rowHigh = len(matrix) - 1



        while(rowLow <= rowHigh):
            colLow = 0
            colHigh = len(matrix[0]) - 1
            outerMid = (rowLow+rowHigh) // 2
            if(target == matrix[outerMid][0] or target == matrix[outerMid][len(matrix[0])-1]):
                return True
            elif(target < matrix[outerMid][0]):
                rowHigh = outerMid - 1
            elif(target > matrix[outerMid][len(matrix[0])-1]):
                rowLow = outerMid + 1
            else:

                while(colLow <= colHigh):
                    innerMid = (colLow + colHigh) // 2
                    if(target == matrix[outerMid][innerMid]):
                        return True
                    elif(target < matrix[outerMid][innerMid]):
                        colHigh = innerMid - 1
                    else:
                        colLow = innerMid + 1
            if(colLow > colHigh): 
                return False
        return False



            #if(target == arr[mid]) return mid
            #if(target < arr[mid]) high = mid - 1
            #if(target > arr[mid]) low = mid + 1