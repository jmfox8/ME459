#Ingest the input and convert to integer
Arg <- commandArgs(trailingOnly = TRUE)
n <- as.integer(Arg)

#Identify the overall size of the array A and initialize with random numbers between -1 and 1
A.total = n*n
A <- array(runif(A.total,-1 ,1), dim=c(n,n))

#initalize vector b of length N, made up of 1s
b <- rep(1.0,n)

#Perform vector multiplication on between Array A and vector b as done in mvmul
c <- rep(0,n)
i = 1
j = 1
runt <- system.time(for(i in 1:n) {
        for (j in 1:n){
                Aval <- i
                c[i] <- c[i] + A[Aval,j] * b[j]
                }
        j = 1
        i = i + 1
        })

#Print the last entry in the new vector c (that is of size N) and the time taken for the multiplication process
print(c[n])
print(runt)

