open BsReactNative;
open BsReactNativePaper;
open Paper;
open Navigation;

module Styles = {
  open Style;

  let container = style([flex(1.0), margin(Pt(10.))]);
};

let component = ReasonReact.statelessComponent("TypographyExample");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  render: self =>
    <StackNavigator.Screen headerTitle="Typography example" navigation>
      ...{
           () =>
             <View style=Styles.container>
               <Headline> {ReasonReact.string("Headline")} </Headline>
               <Title> {ReasonReact.string("Title")} </Title>
               <Subheading> {ReasonReact.string("Subheading")} </Subheading>
               <Text> {ReasonReact.string("Text")} </Text>
               <Paragraph> {ReasonReact.string("Paragraph")} </Paragraph>
               <Caption> {ReasonReact.string("Caption")} </Caption>
             </View>
         }
    </StackNavigator.Screen>,
};
