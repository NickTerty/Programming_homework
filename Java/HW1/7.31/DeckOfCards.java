package card;
//DeckOfCards class represents a deck of playing cards.
import java.security.SecureRandom;

public class DeckOfCards{
    // random number generator
    private static final SecureRandom randomNumbers = new SecureRandom();
    private static final int NUMBER_OF_CARDS = 52; // constant # of Cards
    
    private Card[] deck = new Card[NUMBER_OF_CARDS]; // Card references
    private int currentCard = 0; // index of next Card to be dealt (0-51)
    private static final String[] FACES = {"Ace", "Deuce", "Three", "Four", "Five", "Six",
    	    "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    private static final String[] SUITS = {"Hearts", "Diamonds", "Clubs", "Spades"};
    
    // constructor fills deck of Cards
    public DeckOfCards(){
        String[] faces = FACES;
        String[] suits = SUITS;
        
        // populate deck with Card objects
        for (int count = 0; count < deck.length; count++){
            deck[count] = new Card(faces[count % 13], suits[count / 13]);
        }
    }
    
    // shuffle deck of Cards with one-pass algorithm
    public void shuffle(){
        // next call to method dealCard should start at deck[0] again
        currentCard = 0;
        
        // for each Card, pick another random Card (0-51) and swap them
        for (int first = 0; first < deck.length; first++){
            // select a random number between 0 and 51
            int second = randomNumbers.nextInt(NUMBER_OF_CARDS);
            
            // swap current Card with randomly selected Card
            Card temp = deck[first];
            deck[first] = deck[second];
            deck[second] = temp;
        }
    }
    
    // deal one Card
    public Card dealCard(){
        // determine whether Cards remain to be dealt
        if (currentCard < deck.length){
            return deck[currentCard++]; // return current Card in array
        }
        else{
            return null; // return null to indicate that all Cards were dealt
        }
    }
    
    /*
     * For Poker game
     */
    
    // deal hand
    public Card[] dealHand() {
    	Card[] hand = new Card[5];
    	for(int i = 0; i < 5; i++) {
    		hand[i] = dealCard();
    	}
    	return hand;
    }
    
    
    public int[] getFaceCount(Card[] hand) {
    	int[] countFace = new int[13]; // e.g. if you have two kings, countFace[12] = 2.
    	for(Card card: hand) {
    		for(int i = 0; i < FACES.length; i++) {
    			if(card.getFace().equals(FACES[i])) {
    				countFace[i]++;
    				break;
    			}
    		}
    	}
    	return countFace;
    }
    
    public int[] getSuitCount(Card[] hand) {
    	int[] countSuit = new int[4]; // e.g. if you have three Diamonds, countSuit[1] = 3.
    	for(Card card: hand) {
    		for(int i = 0; i < SUITS.length; i++) {
    			if(card.getFace().equals(FACES[i])) {
    				countSuit[i]++;
    				break;
    			}
    		}
    	}
    	return countSuit;
    }
    
    public boolean hasPair(Card[] hand) {
    	int[] countFace = getFaceCount(hand);
    	int pairCount = 0;
    	boolean hasThree = false;
    	
    	for(int i = 0; i<countFace.length; i++) {
    		if(countFace[i] == 2) {
    			pairCount++;
    		}
    		else if(countFace[i] == 2) {
    			hasThree = true;
    		}
    	}

    	return pairCount == 1 && !hasThree;
    }
    
    public boolean hasTwoPair(Card[] hand) {
    	int[] countFace = getFaceCount(hand);
    	int pairCount = 0;
    	for(int i = 0; i<countFace.length; i++) {
    		if(countFace[i] == 2) {
    			pairCount++;
    		}
    	}

    	return pairCount == 2;
    }
    
    public boolean hasThreeOfAKind(Card[] hand) {
    	int[] countFace = getFaceCount(hand);
    	int kindCount = 0;
    	for(int i = 0; i < countFace.length; i++) {
    		if(countFace[i] == 3) {
    			kindCount++;
    			break;
    		}
    	}
    	
    	return kindCount == 1;
    }
    
    public boolean hasFourOfAKind(Card[] hand) {
    	int[] countFace = getFaceCount(hand);
    	int fourKindCount = 0;
    	for(int i = 0; i < countFace.length; i++) {
    		if(countFace[i] == 4) {
    			fourKindCount++;
    			break;
    		}
    	}
    	
    	return fourKindCount == 1;
    }
    
    public boolean hasFlush(Card[] hand) {
    	int[] countSuit = getSuitCount(hand);
    	for(int count : countSuit) {
    		if(count == 5) {
    			return true;
    		}
    	}
    	return false;
    }
    
    public boolean hasStraight(Card[] hand) {
    	// A~9
    	int[] countFace = getFaceCount(hand);
    	for (int i = 0; i <= 8; i++) {
            if (countFace[i] == 1 && countFace[i+1] == 1 && countFace[i+2] == 1 
                && countFace[i+3] == 1 && countFace[i+4] == 1) {
                return true;
            }
        }
    	
    	// 10 J Q K A
    	if (countFace[0] == 1 && countFace[9] == 1 && countFace[10] == 1 
    			&& countFace[11] == 1 && countFace[12] == 1) {
    		return true;
    	}
    
    	return false;
    }
    
    public boolean hasFullHouse(Card[] hand) {
    	return hasPair(hand) && hasThreeOfAKind(hand);
    }
    
}
