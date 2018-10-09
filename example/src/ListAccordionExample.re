open BsReactNative;
open Paper;
open Navigation;

module Styles = {
  open Style;

  let container = style([flex(1.0)]);

  let accordion = style([flexDirection(Row), alignItems(Center)]);
};

let component = ReasonReact.statelessComponent("ListAccordion Example");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  render: _self =>
    <StackNavigator.Screen headerTitle="ListAccordion" navigation>
      ...{
           () =>
             <ScrollView style=Styles.container>
               <List.Section title="Expandable list item">
                 <List.Accordion
                   style=Styles.accordion
                   left={
                     List.renderIcon((props: List.iconProps) =>
                       <List.Icon
                         icon={Icon.Name("folder")}
                         color={props.color}
                       />
                     )
                   }
                   title="Expandable list item">
                   <List.Item title="List item 1" />
                   <List.Item title="List item 2" />
                 </List.Accordion>
               </List.Section>
               <Divider />
               <List.Section title="Expandable & multiline list item">
                 <List.Accordion
                   title="Expandable list item"
                   description="Describes the expandable list item">
                   <List.Item title="List item 1" />
                   <List.Item title="List item 2" />
                 </List.Accordion>
               </List.Section>
               <Divider />
               <List.Section title="Expandable list with icons">
                 <List.Accordion
                   left={
                     List.renderIcon((props: List.iconProps) =>
                       <List.Icon
                         icon={
                           Icon.Element(
                             Icon.renderIcon((iconProps: Icon.iconProps) =>
                               <RNIcons.MaterialIcons
                                 name=`_star
                                 color={iconProps.color}
                                 size={iconProps.size}
                               />
                             ),
                           )
                         }
                         color={props.color}
                       />
                     )
                   }
                   title="Accordion item 1">
                   <List.Item
                     left={
                       List.renderIcon((props: List.iconProps) =>
                         <List.Icon
                           icon={Icon.Name("thumb-up")}
                           color={props.color}
                         />
                       )
                     }
                     title="List item 1"
                   />
                   <List.Item
                     left={
                       List.renderIcon((props: List.iconProps) =>
                         <List.Icon
                           icon={
                             Icon.Element(
                               Icon.renderIcon((iconProps: Icon.iconProps) =>
                                 <RNIcons.MaterialIcons
                                   name=`_thumbDown
                                   color={iconProps.color}
                                   size={iconProps.size}
                                 />
                               ),
                             )
                           }
                           color={props.color}
                         />
                       )
                     }
                     title="List item 2"
                   />
                 </List.Accordion>
               </List.Section>
             </ScrollView>
         }
    </StackNavigator.Screen>,
};
