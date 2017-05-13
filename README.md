# Project---Predictive-Rock-Paper-Scissor-AI

*See documentation.pdf for class diagram, white box description, unit testing & performance analysis

In its essence, the system uses a swarm mind algorithm which combines 15 schemes built using 5 different classes.

The objective of the swarm mind is to predict the opponent’s (human or other AI) next move in an iterative Rock-Paper-Scissor game of 1000 rounds through majority consensus: each algorithm, out of the 15 total schemes, generates 1 prediction per round (Rock, paper or scissor) and the most overwhelmingly common majority prediction is used as the next move to be played. In the absence of a majority consensus from the system OR if previous swarm consensus did not result in sufficient victories, the most overwhelmingly successful individual algorithm out of the 15 schemes is used to predict the next game move to be played. Lastly, in the absence of an overwhelmingly successful algorithm, a random move is picked to be played. The 15 schemes are grouped and orchestrated by one single umbrella Class, called Player_Manager. 

Note: As the requirements of the project focuses on predicting previous-to-next move patterns, the system is purposely biased towards the requirement by having an over-representation of schemes possessing the ability to detect previous-to-next move correlations in the swarm. The statistical and practical impact of such bias has not been thoroughly examined and will be outside the scope of the project.   

Reasoning behind architecture decision:
From a statistical perspective, the advantage of using a swarm mind is two fold:
Increase confidence interval when picking the next move to be played.
Potential for emerging pattern detection abilities: by giving each scheme the ability to detect a specific but different type of pattern or learning formula, the combined system may detect emerging/non-hardcoded pattern not detectable by individual schemes.
The disadvantage of a swamp mind is the following:
a majority does not guarantee an adequate move and may be subject to majority biais
However, as mentioned earlier, this bias is fully attenuated since the system may pick the best performing individual scheme over the majority consensus under some circumstances.

Furthermore, in the case of when an overwhelmingly successful scheme is selected, the RPS system can also be viewed as a primitive-evolutionary algorithm in which the best strategy is picked while the least performing are relegated, but kept in the “gene pole” in case these genes become advantageous when facing future environmental changes.
 
Algorithm descriptions for each of the 15 algorithms:
Basic schemes:
Scheme 1: Random play. No detection abilities nor adaptive abilities. Used as default when no consensus is reached and no scheme is overwhelmingly successful. Predictions made by scheme 1 are excluded from swarm majority voting.
Scheme 2: Hardcoded psychological RPS play pattern of an average human player based on published research studies.  No adaptive abilities. 
Scheme 3: Detects correlations between the opponent’s last move and the new move. Results are further subdivided depending on either the opponent’s last move was a Lost, a Draw or a Win for the opponent.  
Advance schemes 1:
Scheme 4-5: Same as scheme 3, but with different beta values for their respective learning formula.
Adv1 Scheme 6-8: Detects correlations between the opponent’s TWO last moves in identical fashion as scheme 3. Each scheme has different beta values for their respective learning formula and different play threshold values.
Adv1 Scheme 9-10: Detects correlations between the opponent’s last TWO moves. Results are however further subdivided depending on either the second last move was a Lost, a Draw or a Win for the opponent.   Each scheme has different beta values for their respective learning formula and different play threshold values.
Adv1 Scheme 11: Detects correlations between the opponent’s three last moves in identical fashion as scheme 3.
Adv1 Scheme 12: Detects correlations between the opponent’s three last moves. Results are further subdivided depending on either the opponent’s second last move was a Lost, a Draw or a Win for the opponent.  
Adv1 Scheme 13: Detects correlations between the opponent’s three last moves. Results are however further subdivided depending on either the third last move was a Lost, a Draw or a Win for the opponent.  
Adv1 Scheme 14: Detects correlations between the opponent’s four last moves in identical fashion as scheme 3.
Schemed 15: Hardcoded pattern scheme for which basic scheme 3 sometimes has no counter. 
(Codes that are present but not activated) Adv2 Scheme 16-25: Detect raw Rock Paper Scissor patterns correlation between opponents from 1 up to 10 last moves. Some schemes are identical, but have different beta values and play minimum thresholds. Due to time constraint and unsatisfactory performances in preliminary testings, these schemes have been omitted in the final design- segments of its codes can however still be seen in the program****
