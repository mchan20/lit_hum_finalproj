library(tidyverse)
library(data.table)
library(tidytext)

illiad <- fread("illiad.csv")

gg <- ggplot(illiad, aes(x=book)) + 
  ggtitle("By-Book Frequency of 'tears' in the Illiad") +
    geom_histogram(binwidth=1, fill="#ba3100", color="#ffffff",size = 1) +
    theme(panel.background = element_rect(fill = "#fac5a3")) +
    scale_x_continuous(breaks = seq(1, 24, 1))
gg

book_24 <- illiad[book == "24"]
bruh <- ggplot(book_24, aes(x=line)) + 
  ggtitle("Book 24 Analysis of Frequency") +
  geom_histogram(binwidth=100, fill="#ba3100", color="#ffffff",size = 1) +
  theme(panel.background = element_rect(fill = "#fac5a3"))
  # scale_x_continuous(breaks = seq(1, , 1))
bruh

# white  "#ffffff"
# red    "#ba3100"
# orange "#f89d5f"
# "#fac5a3"

aeneid <- fread("aeneid.csv")
# aeneid <- aeneid[book != 6]

gg.2 <- ggplot(aeneid, aes(x=book)) + 
  ggtitle("By-Book Frequency of 'tears' in the Aeneid") +
  geom_histogram(binwidth=1, fill="#ee3f19", color="#291e0c",size = 1) +
  theme(panel.background = element_rect(fill = "#fdf0cb")) +
  scale_x_continuous(breaks = seq(1, 12, 1))
gg.2

# red   "#ee3f19"
# cream "#f6e6b8"
# black "#291e0c"

data("stop_words")

search_words <- c("tear", "tears", "weep", "wept", "mourning","grieve", "grieving")
#count most frequent words in illiad around tears
word_counts_illiad <- illiad %>% unnest_tokens(output = word, input = text) %>%  
  anti_join(stop_words) %>% 
  count(word, sort = TRUE) %>% 
  filter(n > 2,n < 17) %>% 
  filter(word %in% )
  


ok <- ggplot(word_counts_illiad, aes(x=word,y=n)) + geom_bar(stat="identity") + coord_flip()
ok

#count most frequent words in aeneid around tears
text_words <- aeneid %>% unnest_tokens(output = word, input = text)
data("stop_words")
text_words  <- text_words  %>% anti_join(stop_words)
text_wordcounts <- text_words  %>% count(word, sort = TRUE)
