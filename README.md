# Parallel_Programming_Illustrations
Performance and Scalability is the key requirement of any software. This involves both scale-up (increasing performance of a software on a single machine) and scale-out (increasing the performance of a software by distributing work across the machines).

Basic concepts of writing a parallel/distributed program are fairly straightforward. To increase the utilization of a software on a single host, program is multi-threaded. When a single system reaches saturation, next step to increase the throughput is distributing work across multiple hosts.

Writing a truly scalable software however is an art. A software developer or performance engineer faces multiple challenges while achieving this goal. Some of the general questions are:

Why my software performance is not scaling with scaling number of threads?
Why my host is underutilized despite increasing the parallelism?
Why my software performance/throughput has not increased despite increase in CPU/Memory resources? Or Worse Why my software performance/throughput has DECREASED depsite increase in CPU/Memory resource?
Writing the perfect parallel algorithms for the software is a key here, but it also important to understand how a software interacts with the operating system/computer hardware.

As a performance development engineer working for more than 12 years, I've faced such questions on a daily basis. In this project, I'm planning to cover some of the basic "performance" aspects of parallel programming, interaction of software with the OS/Hardware & set of diagnostics tools that we can use to uncover such issues in an complex software code consisting of thousands to millions of lines of code where finding the bottleneck is not trivial.

I'll try to use small "Hello World" kind of programs for the illustrations of performance issues so that anyone can copy and execute these program on their hardware. Some of the performance tools I'll use for diagnosis

Linux Perf
eBPF
Intel Vtune Analyzer
Intel PCM
Other system tools
I'll keep on writing the illustrations, share performance data and write an article as I get some free time.

Sanket.

