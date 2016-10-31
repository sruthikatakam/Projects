/Multiple Choice Quiz.
//To add a question, all you have to do is add a question to the end of the question array
//and add its 3 possible answers to the end of the answers array.

//Array of possible questions.
var questions = ["What is the capital of Spain?", "What year did World War 2 begin?", "What shape is the earth?", "Where does paper come from?", "What noise does a cow make?", "How many eyes does a human have?",
				 "What do you put rubbish in?", "What gets wetter the more it dries?", "How many days are in the month November?", "What month is Halloween?"];

//Matching array of answers. Each point of the array corresponds to the point of its question eg. answers[0][] matches question[0].				 
var answers = [ ["Madrid", "London", "Barcelona"], ["1939", "1914", "1941"], ["Sphere", "Cube", "Flat"], ["Trees", "Potatoes", "WHS Smith"], ["Moo", "Oink", "Meow"], ["Two", "One", "Twenty"],
				["A Bin", "Your Mouth", "The Floor"], ["A Towel", "Water", "Soil"], ["30", "29", "31"], ["October", "December", "May"] ];

var askedQuestions = [];	//Stores the questions that get asked.

var savedAnswers = [];		//Stores the users answers.

var c1, c2, c3;				//Stores the choice1-3 divs where the possible answers for each question will be displayed using.
var random;					//Will hold a random value to be get a random question from the questions array.
var q;						//Stores the quest section div so its innerHTML can be changed.

var amountOfQuestions;		//stores the amount of questions, taken from the select box on quiz.html when user starts quiz.
var questCounter;			//questCounter stores the div where currentQuest/amount of questions will be displayed to user.
var currentQuest = 0;		//currentQuest will display to user what question they are on.

var radioButtons, nextButton; //These store radio button div and button id so they can be hidden before test starts.

//Called when quiz.html first loads, updates the select box depending on the size
//of the questions array (how many questions there are).
function setSelectBox()
{
	var qA = document.getElementById('QuestAmount');
	for(var i = 0;i<questions.length;i++)
	{
		var j = i+1;	//j is used instead of i so the select box starts at 1, not 0.
		if(j==5)
			qA.innerHTML += '<option value="' + j + '"  selected="selected">' + j + '</option>';
		else
			qA.innerHTML += '<option value="' + j + '">' + j + '</option>';
	}
}

//Called when quiz.html first loads. 
function hideButtons()
{
	radioButtons = document.getElementById('radioButtons');
	nextButton = document.getElementById('nextButton');
    radioButtons.style.display = 'none';
	nextButton.style.display = 'none';
}

//Called when the user clicks start quiz button, displays required elements for quiz
//and sets up variables.
function startQuiz(questAmount)
{	
	amountOfQuestions = questAmount;
	
	q = document.getElementById('QuestSection');
	questCounter = document.getElementById('questCounter');
	radioButtons.style.display = 'block';
	nextButton.style.display = 'block';
	
	c1 = document.getElementById('choice1');
	c2 = document.getElementById('choice2');
	c3 = document.getElementById('choice3');
	
	newQuestion();
	
}

//Gets a random question from the question array (if it hasn't already been asked, will keep looping
//until an unasked question is found using the askedQuestions array).
function newQuestion()
{		
	questCounter.innerHTML = ("Question " + (currentQuest+1) + "/" + amountOfQuestions)
	
	random = Math.floor(Math.random() * questions.length);
	
	var questionAsked = false;
	
	for(var i=0;i<askedQuestions.length;i++)
		if(askedQuestions[i] == questions[random])
				 questionAsked = true;
	
	if(questionAsked)
		newQuestion();
	
	//If question hasn't already been asked, will display it to user.
	else
	{
		q.innerHTML = questions[random];
		askedQuestions.push(questions[random]);	
		currentQuest++;
		
		var randoms = [];
		
		//Used to store 3 unique random values from 0-2 in the randoms array.
		while(randoms.length < answers[random].length)
		{
			var random2 = Math.floor(Math.random() * answers[random].length);
			var notNew = false;
			for(var i = 0; i<randoms.length;i++)
				if(randoms[i] == random2)
				{
					notNew = true;
					break;
				}
			
			if(!notNew)
				randoms.push(random2);
				
		}
		
		//Possible answers to the question displayed in random order each time using the randoms array.
		c1.innerHTML = answers[random][randoms[0]];
		c2.innerHTML = answers[random][randoms[1]];
		c3.innerHTML = answers[random][randoms[2]];
	}
	
	if((currentQuest) == amountOfQuestions)
	{
		finishTest();
	}
}

//Checks which radio button is checked and stores the innerHTML value of its corresponding
//div e.g. radio button 1 to c1(choice1), in the savedAnswers array.
function saveAnswer()
{
	var answer;
	
	radio1 = document.getElementById('radio1');
	radio2 = document.getElementById('radio2');
	radio3 = document.getElementById('radio3');
	
	if(radio1.checked)
		answer = c1.innerHTML;
	else if(radio2.checked)
		answer = c2.innerHTML;
	else if(radio3.checked)
		answer = c3.innerHTML;
	
	savedAnswers.push(answer);
}

//Called when current question is equal to the amount of questions.
function finishTest()
{
	nextButton.value = 'Finish Test';
	nextButton.onclick = displayResults;
}

//Using askedQuestions array, savedAnswers array combined with questions and answers arrays
//the user is informed of the question they where asked, what they answered, the correct answer and their score.
function displayResults()
{	
	saveAnswer();
	hideButtons();
	questCounter.innerHTML = "Quiz Complete. Your results are below.";
	q.innerHTML="";
	var correctAnswers = 0;
	
	for(var i=0;i<askedQuestions.length;i++)
	{	
		q.innerHTML += ("<br>Question " + (i+1) + ": " + askedQuestions[i] +"<br>");
		q.innerHTML += ("You answered: <b>" + savedAnswers[i] + "</b><br>");
		
		for(var j=0;j<questions.length;j++)
			if(askedQuestions[i] == questions[j])
			{
				if(savedAnswers[i] == answers[j][0])
				{
					q.innerHTML += "This is correct <br>";
					correctAnswers++;
				}
				else
					q.innerHTML += "This was incorrect. The correct answer was " + answers[j][0] + ".<br>";
			}
	}
	
	q.innerHTML += "<br> You scored " + correctAnswers + "/" + amountOfQuestions + ". " + Math.round((correctAnswers/amountOfQuestions * 100)) + "%.<br><br>";
	q.innerHTML += '<a href="quiz.html">Click here to begin a new quiz.</a>'
	
}