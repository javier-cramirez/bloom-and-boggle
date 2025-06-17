# bloom-and-boggle

A small library for implementing a Boggle solver using:
- a boggle filter for detecting false negatives, with a small probability ($\epsilon$) for detecting false positives
- a trie (prefix tree) for fast lookups depending on the boggle filter's answer to query $q$

Boggle filters enable us to create a dictionary of all valid tokens, with small memory footprint. Of course, this depends on 
our choice for $\epsilon$ which trades memory for false positive accuracy. 

## TO-DO
- Work on the Boggle solver UI 
- Test the trie


