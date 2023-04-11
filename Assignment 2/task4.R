#Ingest the input and convert to integer
Arg <- commandArgs(trailingOnly = TRUE)
N <- as.integer(Arg)

#Identify the overall size of the array A and initialize with random numbers be$
A.total = N*N
A <- array(runif(A.total, min=-1, max=1), dim=c(N,N))

#initalize vector b of length N, made up of 1s
b <- rep(1,N)

#Perform vector multiplication on between Array A and vector b
c = A%*%b

#Print the last entry in the new vector c (that is of size N)
cat(c("The last entry of vector c is: ", c[N],"\n"))
