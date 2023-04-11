row = 3400
column = 1400

size = row * column
A <- array(runif(row*column, min = -1, max = 1), c(row,column))
B <- array(runif(row*column, min = -1, max = 1), c(row,column))

cat(A[row,column],B[row,column],"\n")

runt_1 <- system.time(for(i in 1:row){
    for(j in 1:column){
        temp1 = A[i,j]
        A[i,j] = B[i,j]
        B[i,j] = temp1
    }
})

cat(A[row,column],B[row,column],"\n")
print(runt_1[3])

runt_2 <-system.time(for(i in 1:column){
    for(j in 1:row){
        temp2 = A[j,i]
        A[j,i] = B[j,i]
        B[j,i] = temp2
    }
})

cat(A[row,column],B[row,column],"\n")
print(runt_2[3])
