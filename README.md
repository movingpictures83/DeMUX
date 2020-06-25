# DeMUX
# Language: C++
# Input: TXT
# Output: DIR
# Tested with: PluMA 1.0, GCC 4.8.4

DeMultiplex sequences into groups, using Qiime (Caporaso et al, 2010).

The plugin takes as input a parameters.txt file of keyword-value pairs (tab-delimited):
sequences: FASTQ file of sequences
mapping: Mapping table of sequence identifiers to barcodes, groups, etc. (TXT)
barcodes: FASTQ file of barcode sequences
barcodetype: Type of barcode used.

The plugin produces as output several files in the user-specified output directory
which will in turn automatically be copied to the parent folder:
histograms (TXT): Statistics
seqs (FNA): Demultiplexed sequences
log file (TXT): Summary


