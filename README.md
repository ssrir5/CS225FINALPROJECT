//READ ME
From within directory "src":
clang++ main.cpp graphtraversal.cpp airports.cpp pathway.cpp -o main && ./main
clang++ ../tests/tests.cpp graphtraversal.cpp airports.cpp pathway.cpp -o test && ./test



# CS 225: Open Flights Final Project
> *By Arul, Jash, Nimish, and Shreyas*

## Introduction 
Motivation: 
* As students who all have busy schedules but still enjoy traveling from time to time, we have found it to be a common concern that flight traveling is always a nuisance. Between flight cancellations and the endless layovers, we have found there to be key disconnects in flight path algorithms that are currently used. 

This project highlights

Functionality:
* Visualization: choropleth maps at the county and state levels for the USA, and country level for the rest of the world
* Slider Feature: changes data across different years
* Hover Feature: shows the county/state/country name and the number of students from that area
* Data Analysis: graphs and analysis components that further break down the data

## Architecture
Front End App: 
* **client**: contains the React App files
  * **src**: this folder houses most of the JavaScript files that are compiled by webpack
    * **components**: 
      * **App**: the parent component that renders the dropdown menu when the app is first started
      * **dropdown**: a menu that opens and closes onclick as well as renders a different map component depending on the type selected
      * **slider**: injects new data into the map component when changed by the user by prompting a new action to update the map states
      * **maps**: reads the csv data and maps it to the data state in the component. A composable map is rendered with geographies that match the data ids to the topojson ids from the geoUrl
  * **public**: 
    * index.hmtl: where the HTML code of the React Components are injected into
    * data.html: highlights a sample data set with zip code data pertinent to students at UIUC
    * stats.html: displays differences in the students at UIUC, split by zip code and charted. The difference highlights a 10 year change from 2009 to 2019.
    * about.html: includes the ReadMe file with instructions of the React App and Data parsing pipeline.

Back end: 
* **data**: 
  * **client**: contains all relevant data files
  * **public**: this folder contains our data parsing and analyzation files in folders *clean-data* and *data-analysis*
    * **components**: 
      * **Data Parsing Pipeline**: script reads in datasets and performs whatever cleaning was necessary (rids file of outliers, etc.)
      * **Visualizations**: files containing data visualizations for all the years; visualizations include pie charts and scatter plots for the year by year data

## Project Setup
1. Clone this GitHub repository
2. Open project and navigate to *client* folder via terminal
3. Run the following line in the terminal to install all necessary dependencies: 
```npm install```
4. Run the following line in the terminal to run the project (make sure it is run in the client folder): 
```npm start```

## Roles
#### Arul: 
Found relevant datasets: Wrote code to clean, and reformat datasets: Performed Data Analysis and created Visualizations
#### Jash: 
Built data parsing pipeline: found relevant datasets, wrote scripts to parse through, clean, and reformat datasets, worked w/ Arul to analyze data
#### Nimish: 
Navigation and Data Visualization: Developed navigation bar, embedded raw datasets and visualizations, and worked w/ Kaitlyn on front-end React App
#### Kaitlyn: 
React App and Components: App, County/State/World Maps, Slider (updating data onChange), Dropdown Menu




