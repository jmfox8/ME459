#pull in file from command line
Arg <- commandArgs(trailingOnly = TRUE)

#read .csv file into data frame
framelist <- read.csv(Arg,header = FALSE)

#convert data frame into numeric matrix
matlist <- data.matrix(framelist)

#run fnorm as the frobenius norm
fnorm <- norm(matlist, "F")

#return the frobenius norm
print(fnorm)
