open BsReactNative;
open Navigation;

module Styles = {
  open Style;

  let listItem = style([padding(Pt(10.))]);

  let listItemText = style([fontSize(Float(16.))]);
};

type screen = {
  id: int,
  name: string,
  route: Config.route,
};

type examples = array(screen);

let examples = [|
  {id: 1, name: "Button Example", route: Config.ButtonExample},
  {id: 2, name: "Checkbox Example", route: Config.CheckboxExample},
  {id: 3, name: "Divider Example", route: Config.DividerExample},
  {id: 4, name: "ListAccordion Example", route: Config.ListAccordionExample},
  {id: 5, name: "ListSection Example", route: Config.ListSectionExample},
  {id: 6, name: "RadioButton Example", route: Config.RadioButtonExample},
  {id: 7, name: "Snackbar Example", route: Config.SnackbarExample},
  {id: 8, name: "Surface Example", route: Config.SurfaceExample},
  {id: 9, name: "Switch Example", route: Config.SwitchExample},
  {id: 10, name: "Typography Example", route: Config.TypographyExample},
|];

let keyExtractor = (item, _index) => string_of_int(item.id);

let renderItem = (navigation: StackNavigator.navigation) =>
  FlatList.renderItem((screen: FlatList.renderBag(screen)) =>
    <Paper.List.Item
      title={screen.item.name}
      style=Styles.listItem
      onPress={
        _event =>
          Js.Global.setTimeout(() => navigation.push(screen.item.route), 0)
          |> ignore
      }
    />
  );

let component = ReasonReact.statelessComponent("Home");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  render: _self =>
    <StackNavigator.Screen headerTitle="Example App" navigation>
      ...{
           () =>
             <View>
               <FlatList
                 data=examples
                 keyExtractor
                 renderItem={renderItem(navigation)}
                 itemSeparatorComponent={
                   FlatList.separatorComponent(
                     (_props: FlatList.separatorProps(screen)) =>
                     <Paper.Divider />
                   )
                 }
               />
             </View>
         }
    </StackNavigator.Screen>,
};
