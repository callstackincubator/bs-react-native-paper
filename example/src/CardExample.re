open BsReactNative;
open BsReactNativePaper;
open Paper;
open Navigation;

module Styles = {
  open Style;

  let container = style([flex(1.0)]);
  let content = style([padding(Pt(4.))]);
  let card = style([margin(Pt(4.))]);
};

let component = ReasonReact.statelessComponent("Card Example");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  render: _self =>
    <StackNavigator.Screen headerTitle="Card example" navigation>
      ...{
           () =>
             <ScrollView
               style=Styles.container contentContainerStyle=Styles.content>
               <Card style=Styles.card>
                 <Card.Cover
                   source={
                     Required(Packager.require("../assets/wrecked-ship.jpg"))
                   }
                 />
                 <Card.Content>
                   <Title> {ReasonReact.string("Abandoned Ship")} </Title>
                   <Paragraph>
                     {
                       ReasonReact.string(
                         "The Abandoned Ship is a wrecked ship located on Route 108 in Hoenn, originally being a ship named the S.S. Cactus. The second part of the ship can only be accessed by using Dive and contains the Scanner.",
                       )
                     }
                   </Paragraph>
                 </Card.Content>
               </Card>
               <Card style=Styles.card>
                 <Card.Cover
                   source={
                     Required(Packager.require("../assets/forest.jpg"))
                   }
                 />
                 <Card.Actions>
                   <Button onPress={_event => ()}>
                     {ReasonReact.string("Share")}
                   </Button>
                   <Button onPress={_event => ()}>
                     {ReasonReact.string("Explore")}
                   </Button>
                 </Card.Actions>
               </Card>
               <Card style=Styles.card>
                 <Card.Content>
                   <Title> {ReasonReact.string("Berries")} </Title>
                   <Caption> {ReasonReact.string("Omega Ruby")} </Caption>
                   <Paragraph>
                     {
                       ReasonReact.string(
                         "Dotted around the Hoenn region, you will find loamy soil, many of which are housing berries. Once you have picked the berries, then you have the ability to use that loamy soil to grow your own berries. These can be any berry and will require attention to get the best crop.",
                       )
                     }
                   </Paragraph>
                 </Card.Content>
               </Card>
               <Card style=Styles.card>
                 <Card.Content>
                   <Title> {ReasonReact.string("Just Strawberries")} </Title>
                 </Card.Content>
                 <Card.Cover
                   source={
                     Required(Packager.require("../assets/strawberries.jpg"))
                   }
                 />
               </Card>
               <Card
                 style=Styles.card
                 onPress={
                   _event =>
                     Alert.alert(~title="The Chameleon is Pressed", ())
                 }>
                 <Card.Cover
                   source={
                     Required(Packager.require("../assets/chameleon.jpg"))
                   }
                 />
                 <Card.Content>
                   <Title>
                     {ReasonReact.string("Pressable Chameleon")}
                   </Title>
                   <Paragraph>
                     {
                       ReasonReact.string(
                         "This is a pressable chameleon. If you press me, I will alert.",
                       )
                     }
                   </Paragraph>
                 </Card.Content>
               </Card>
               <Card
                 style=Styles.card
                 onLongPress={
                   _event =>
                     Alert.alert(~title="The City is Long Pressed", ())
                 }>
                 <Card.Cover
                   source={Required(Packager.require("../assets/city.jpg"))}
                 />
                 <Card.Content>
                   <Title>
                     {ReasonReact.string("Long Pressable City")}
                   </Title>
                   <Paragraph>
                     {
                       ReasonReact.string(
                         "This is a long press only city. If you long press me, I will alert.",
                       )
                     }
                   </Paragraph>
                 </Card.Content>
               </Card>
             </ScrollView>
         }
    </StackNavigator.Screen>,
};
