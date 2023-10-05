import java.util.Scanner;

public class lottery_ticket {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    // Generate a random three-digit lottery number
    int lotteryNumber = (int) (Math.random() * 1000);

    System.out.print("Enter a three-digit number: ");
    int userNumber = sc.nextInt();

    // Extract individual digits from the user input and lottery number
    int lotteryDigit1 = lotteryNumber / 100;
    int lotteryDigit2 = (lotteryNumber / 10) % 10;
    int lotteryDigit3 = lotteryNumber % 10;

    int userDigit1 = userNumber / 100;
    int userDigit2 = (userNumber / 10) % 10;
    int userDigit3 = userNumber % 10;

    System.out.println("Lottery Number: " + lotteryNumber);

    if (userNumber == lotteryNumber) {
      System.out.println("Congratulations! You have won $10,000.");
    } else if ((userDigit1 == lotteryDigit1 && userDigit2 == lotteryDigit2 && userDigit3 == lotteryDigit3)
        ||
        (userDigit1 == lotteryDigit1 && userDigit3 == lotteryDigit2
            && userDigit2 == lotteryDigit3)
        ||
        (userDigit2 == lotteryDigit1 && userDigit1 == lotteryDigit2
            && userDigit3 == lotteryDigit3)
        ||
        (userDigit2 == lotteryDigit1 && userDigit3 == lotteryDigit2
            && userDigit1 == lotteryDigit3)
        ||
        (userDigit3 == lotteryDigit1 && userDigit1 == lotteryDigit2
            && userDigit2 == lotteryDigit3)
        ||
        (userDigit3 == lotteryDigit1 && userDigit2 == lotteryDigit2
            && userDigit1 == lotteryDigit3)) {
      System.out.println("Congratulations! You have won $3,000.");
    } else if (userDigit1 == lotteryDigit1 || userDigit1 == lotteryDigit2 || userDigit1 == lotteryDigit3 ||
        userDigit2 == lotteryDigit1 || userDigit2 == lotteryDigit2
        || userDigit2 == lotteryDigit3 ||
        userDigit3 == lotteryDigit1 || userDigit3 == lotteryDigit2
        || userDigit3 == lotteryDigit3) {
      System.out.println("Congratulations! You have won $1,000.");
    } else {
      System.out.println("Sorry, you didn't win any prize.");
    }

    sc.close();
  }
}